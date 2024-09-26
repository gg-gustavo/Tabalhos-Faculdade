#include <stdio.h>
#include "io.h"
#include "descricao.h"
#include "filtro.h"
#include "selecao.h"
#include "faltantes.h"
#include "ordena.h"
#include "salvar.h"

void exibirMenu();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo.csv>\n", argv[0]);
        return 1;
    }

    const char *nome_arquivo = argv[1];
    DadosCSV *dados = lerCSV(nome_arquivo);

    if (dados == NULL) {
        fprintf(stderr, "Erro ao ler o arquivo %s\n", nome_arquivo);
        return 1;
    }

    int escolha;
    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        getchar(); // Limpar o buffer de entrada

        switch (escolha) {
            case 1:
                printf("Resumo do arquivo %s:\n", nome_arquivo);
                mostrarResumo(dados);
                break;
            case 2:
                mostrarDadosFormatados(dados);
                break;
            case 3:
                aplicarFiltro(dados);
                break;
            case 4: {
                char nomeColuna[100];
                printf("Entre com a variável: ");
                scanf("%99s", nomeColuna);
                int c;
                while ((c = getchar()) != '\n' && c != EOF) { }

                if (strcmp(nomeColuna, "Idade") == 0) {
                    descreverVariavelNumerica(dados, nomeColuna);
                } else {
                    descreverVariavelCategorica(dados, nomeColuna);
                }
                break;
            }
            case 5: {
                char nomeColuna[100];
                char ordem;
                printf("Entre com a variável de ordenação: ");
                scanf("%99s", nomeColuna);
                getchar(); // Limpar o buffer de entrada

                printf("Ordem (A - Ascendente, D - Descendente): ");
                scanf("%c", &ordem);
                getchar(); // Limpar o buffer de entrada

                ordenarDados(dados, nomeColuna, ordem);
                printf("Dados ordenados com sucesso.\n");
                break;
            }
            case 6:
                selecionarColunas(dados);
                break;
            case 7:
                tratarDadosFaltantes(dados);
                break;
            case 8:{
                char nomeArquivo[256];
                printf("Entre com o nome do arquivo para salvar os dados: ");
                scanf("%255s", nomeArquivo);
                gravarDadosCSV(dados, nomeArquivo);
                break;
            }
            case 9:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
                break;
        }
    } while (escolha != 9);

    liberarDadosCSV(dados);

    return 0;
}

void exibirMenu() {
    printf("\n1) Sumário do Arquivo\n");
    printf("2) Mostrar\n");
    printf("3) Filtros\n");
    printf("4) Descrição dos Dados\n");
    printf("5) Ordenação\n");
    printf("6) Seleção\n");
    printf("7) Dados Faltantes\n");
    printf("8) Salvar Dados\n");
    printf("9) Fim\n");
}