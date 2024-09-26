#include "ordena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variável global para armazenar o índice da coluna para comparação
static int indiceColunaGlobal;

// Função de comparação para qsort
int comparar_qsort(const void *a, const void *b) {
    char *const *linhaA = *(char **const *)a;
    char *const *linhaB = *(char **const *)b;
    return strcmp(linhaA[indiceColunaGlobal], linhaB[indiceColunaGlobal]);
}

// Função para encontrar o índice da coluna para a ordenação qsort
int encontrarIndiceColuna_qsort(DadosCSV *csv, const char *nomeColuna) {
    for (int i = 0; i < csv->num_colunas; i++) {
        if (strcmp(csv->cabecalhos[i], nomeColuna) == 0) {
            return i;
        }
    }
    return -1;
}

// Função para ordenar os dados
void ordenarDados(DadosCSV *csv, const char *nomeColuna, char ordem) {
    indiceColunaGlobal = encontrarIndiceColuna_qsort(csv, nomeColuna);
    if (indiceColunaGlobal == -1) {
        printf("Coluna não encontrada.\n");
        return;
    }
    
    qsort(csv->dados, csv->num_linhas, sizeof(char **), comparar_qsort);

    // Se a ordem for descendente, inverter os dados após a ordenação ascendente
    if (ordem == 'D') {
        for (int i = 0; i < csv->num_linhas / 2; i++) {
            char **temp = csv->dados[i];
            csv->dados[i] = csv->dados[csv->num_linhas - i - 1];
            csv->dados[csv->num_linhas - i - 1] = temp;
        }
    }
}

// Função para gravar os dados ordenados em um arquivo
void gravarDadosOrdenados(DadosCSV *csv, const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "w");
    if (!file) {
        printf("Não foi possível criar o arquivo %s\n", nomeArquivo);
        return;
    }

    // Escrever cabeçalho
    for (int i = 0; i < csv->num_colunas; i++) {
        fprintf(file, "%s", csv->cabecalhos[i]);
        if (i < csv->num_colunas - 1) fprintf(file, ",");
    }
    fprintf(file, "\n");

    // Escrever dados
    for (int i = 0; i < csv->num_linhas; i++) {
        for (int j = 0; j < csv->num_colunas; j++) {
            fprintf(file, "%s", csv->dados[i][j]);
            if (j < csv->num_colunas - 1) fprintf(file, ",");
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Arquivo gravado com sucesso: %s\n", nomeArquivo);
}
