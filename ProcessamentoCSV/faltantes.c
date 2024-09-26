#include "faltantes.h"
#include <stdio.h>
#include <string.h>

// Função para listar registros com valores "NaN" (não disponíveis)
void listarNaN(DadosCSV *csv) {
    printf("Linhas com dados faltantes:\n");
    for (int i = 0; i < csv->num_linhas; i++) {
        int hasNaN = 0;
        for (int j = 0; j < csv->num_colunas; j++) {
            if (strcmp(csv->dados[i][j], "NaN") == 0) {
                hasNaN = 1;
                break;
            }
        }
        if (hasNaN) {
            for (int j = 0; j < csv->num_colunas; j++) {
                printf("%s\t", csv->dados[i][j]);
            }
        }
    }
}

// Função para substituir valores "NaN" pela média dos valores válidos na mesma coluna
void substituirPorMedia(DadosCSV *csv) {
    for (int j = 0; j < csv->num_colunas; j++) {
        if (csv->tipo_coluna[j] == 'N') {  // Processa apenas colunas numéricas
            double soma = 0;
            int count = 0;

            // Calcula a soma e conta valores não-"NaN"
            for (int i = 0; i < csv->num_linhas; i++) {
                if (strcmp(csv->dados[i][j], "NaN") != 0) {
                    soma += atof(csv->dados[i][j]);
                    count++;
                }
            }

            // Calcula a média
            if (count > 0) {
                double media = soma / count;
                char mediaStr[50];
                sprintf(mediaStr, "%.2f", media);

                // Substitui "NaN" pela média calculada
                for (int i = 0; i < csv->num_linhas; i++) {
                    if (strcmp(csv->dados[i][j], "NaN") == 0) {
                        free(csv->dados[i][j]);  // Libera a memória do "NaN" original
                        csv->dados[i][j] = strdup(mediaStr);  // Copia a média como string
                    }
                }
            }
        }
    }
    printf("Substituição por média concluída.\n");
}

// Função para substituir valores "NaN" pelo próximo valor válido na mesma coluna
void substituirProximoValido(DadosCSV *csv) {
    for (int j = 0; j < csv->num_colunas; j++) {
        for (int i = 0; i < csv->num_linhas - 1; i++) {  // Evita verificar a última linha aqui
            if (strcmp(csv->dados[i][j], "NaN") == 0) {
                // Encontra o próximo valor válido
                for (int k = i + 1; k < csv->num_linhas; k++) {
                    if (strcmp(csv->dados[k][j], "NaN") != 0) {
                        free(csv->dados[i][j]);  // Libera a memória do "NaN" original
                        csv->dados[i][j] = strdup(csv->dados[k][j]);  // Copia o próximo valor válido
                        break;
                    }
                }
            }
        }
    }
    printf("Substituição pelo próximo valor válido concluída.\n");
}

// Função para remover linhas que contenham valores "NaN" em qualquer coluna
void removerNaN(DadosCSV *csv) {
    int i = 0;
    while (i < csv->num_linhas) {
        int hasNaN = 0;
        for (int j = 0; j < csv->num_colunas; j++) {
            if (strcmp(csv->dados[i][j], "NaN") == 0) {
                hasNaN = 1;
                break;
            }
        }
        if (hasNaN) {
            // Remove a linha i
            for (int j = 0; j < csv->num_colunas; j++) {
                free(csv->dados[i][j]);  // Libera a memória dos dados da linha
            }
            free(csv->dados[i]);  // Libera a memória da própria linha

            // Desloca todas as linhas subsequentes uma posição para cima
            for (int k = i; k < csv->num_linhas - 1; k++) {
                csv->dados[k] = csv->dados[k + 1];  // Move o ponteiro da linha para cima
            }
            csv->num_linhas--;  // Decrementa o contador de linhas
        } else {
            i++;  // Avança para a próxima linha se não foi removida
        }
    }
    printf("Remoção de linhas com dados faltantes concluída.\n");
}

// Função principal para tratar dados faltantes com opções interativas
void tratarDadosFaltantes(DadosCSV *csv) {
    int escolha;
    do {
        printf("\nTratamento de Dados Faltantes:\n");
        printf("1) Listar registros com NaN\n");
        printf("2) Substituir por média\n");
        printf("3) Substituir pelo próximo valor válido\n");
        printf("4) Remover registros com NaN\n");
        printf("5) Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                listarNaN(csv);
                break;
            case 2:
                substituirPorMedia(csv);
                break;
            case 3:
                substituirProximoValido(csv);
                break;
            case 4:
                removerNaN(csv);
                break;
            case 5:
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 5);
}
