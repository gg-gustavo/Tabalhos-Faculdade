import subprocess

def run_test(test_number, input_data, file):
    """
    Executa o programa em C com os dados de teste e escreve o resultado no arquivo.
    
    :param test_number: Número do teste
    :param input_data: Dados de entrada para o programa
    :param file: Objeto de arquivo para escrever os resultados
    """
    # Executa o programa C e coleta a saída e erros
    process = subprocess.Popen(
        ["./ordenacao"], 
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    # Envia os dados para o stdin do programa C e pega a saída e erros
    output, errors = process.communicate(input=input_data)

    # Escreve a saída do programa C no arquivo com formatação
    file.write(f"TESTE {test_number}:\n")
    file.write(output + "\n")
    
    # Caso tenha ocorrido algum erro, escreve também no arquivo
    if errors:
        file.write("Errors:\n" + errors + "\n")


# Entrada comum para todos os testes
# 1º Tamanho do vetor, 2º Deseja imprimir, 3º Buscar, 4º Elemento a ser buscado, 
# 5º Tipo de Busca, 6º Tipo de Algoritmo
input_data = (
    "<Tam_Vet>\n<S_N>\n<Ord_Busc_SAIR>\n<Chave>\n<Tipo_Busca>\n<Tipo_Alg>\n"
)

# Abre o arquivo para salvar os resultados dos testes
with open("busca_seq_it_1.txt", "w") as file:
    # Executa três testes com diferentes entradas
    for i in range(1, 4):
        run_test(i, input_data, file)
