#include "selecao.h"
#include <stdio.h>
#include <string.h>

void selecionarColunas(DadosCSV *csv) {
    char input[1024];
    printf("Entre com as variáveis que deseja selecionar (separadas por espaço): ");
    fgets(input, 1024, stdin);  // Lê a linha inteira de entrada

    char *nomeColuna = strtok(input, " \n");
    int indices[csv->num_colunas];
    int num_indices = 0;

    while (nomeColuna != NULL && num_indices < csv->num_colunas) {
        int idx = encontrarIndiceDaColuna(csv, nomeColuna);
        if (idx != -1) {
            indices[num_indices++] = idx;
        } else {
            printf("Coluna '%s' não encontrada.\n", nomeColuna);
        }
        nomeColuna = strtok(NULL, " \n");
    }

    if (num_indices > 0) {
        for (int i = 0; i < csv->num_linhas; i++) {
            for (int j = 0; j < num_indices; j++) {
                printf("%s\t", csv->dados[i][indices[j]]);
            }
            printf("\n");
        }

        char escolha;
        printf("Deseja gravar um arquivo com as variáveis selecionadas? [S|N]: ");
        scanf(" %c", &escolha);
        if (escolha == 'S' || escolha == 's') {
            char nomeArquivo[100];
            printf("Entre com o nome do arquivo: ");
            scanf("%99s", nomeArquivo);
            gravarDadosFiltradosParciais(csv, nomeArquivo, indices, num_indices);
        }
    } else {
        printf("Nenhuma coluna válida selecionada.\n");
    }
}

void gravarDadosFiltradosParciais(DadosCSV *csv, const char *nomeArquivo, int *indices, int num_indices) {
    FILE *file = fopen(nomeArquivo, "w");
    if (!file) {
        printf("Não foi possível criar o arquivo %s\n", nomeArquivo);
        return;
    }
    for (int i = 0; i < csv->num_linhas; i++) {
        for (int j = 0; j < num_indices; j++) {
            fprintf(file, "%s,", csv->dados[i][indices[j]]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Arquivo gravado com sucesso: %s\n", nomeArquivo);
}
