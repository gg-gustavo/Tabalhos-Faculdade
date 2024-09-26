#include <stdio.h>
#include "salvar.h"

// Função para gravar os dados de uma estrutura DadosCSV em um arquivo CSV.
void gravarDadosCSV(DadosCSV *dados, const char *nome_arquivo) {
    // Tentativa de abrir o arquivo para escrita. Se falhar, mostra um erro e sai da função.
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo %s para escrita.\n", nome_arquivo);
        return;
    }

    // Iterar sobre cada linha dos dados.
    for (int i = 0; i < dados->num_linhas; i++) {
        // Iterar sobre cada coluna da linha atual.
        for (int j = 0; j < dados->num_colunas; j++) {
            // Escrever o valor atual no arquivo, seguido de uma vírgula, exceto após o último valor da linha.
            fprintf(arquivo, "%s", dados->dados[i][j]);
            if (j < dados->num_colunas - 1) {
                fprintf(arquivo, ","); // Delimitador CSV
            }
        }
        // Após terminar de escrever todos os valores de uma linha, escrever uma quebra de linha.
        fprintf(arquivo, "\n");
    }

    // Fechar o arquivo após a escrita ser concluída.
    fclose(arquivo);
    // Informar ao usuário que os dados foram salvos com sucesso.
    printf("Dados salvos com sucesso em %s.\n", nome_arquivo);
}
