#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "filtro.h"

// Função auxiliar para comparar valores com o filtro aplicado
int cumprirFiltro(char *valor, const char *operador, const char *ref) {
    double numValor, numRef;
    if (strcmp(operador, "==") == 0) {
        return strcmp(valor, ref) == 0;
    } else if (strcmp(operador, "!=") == 0) {
        return strcmp(valor, ref) != 0;
    } else {
        numValor = atof(valor);
        numRef = atof(ref);
        if (strcmp(operador, ">") == 0) {
            return numValor > numRef;
        } else if (strcmp(operador, "<") == 0) {
            return numValor < numRef;
        } else if (strcmp(operador, ">=") == 0) {
            return numValor >= numRef;
        } else if (strcmp(operador, "<=") == 0) {
            return numValor <= numRef;
        }
    }
    return 0;
}

void mostrarDadosFormatadosParcial(DadosCSV *csv, int *indices, int num_indices) {
    // Implementação similar a mostrarDadosFormatados, mas iterando sobre 'indices'
    for (int idx = 0; idx < num_indices; idx++) {
        int i = indices[idx];
        printf("%d ", i);
        for (int j = 0; j < csv->num_colunas; j++) {
            printf("%s ", csv->dados[i][j]);
        }
        printf("\n");
    }
}

// Função principal para aplicar filtros
void aplicarFiltro(DadosCSV *csv) {
    char coluna[100], operador[3], valor[100];
    printf("Entre com a variavel: ");
    scanf("%99s", coluna);
    printf("Escolha um filtro ( == > >= < <= != ): ");
    scanf("%2s", operador);
    printf("Digite um valor: ");
    scanf("%99s", valor);

    int indice = encontrarIndiceDaColuna(csv, coluna);
    if (indice == -1) {
        printf("Coluna não encontrada.\n");
        return;
    }

    int *filtrados = malloc(csv->num_linhas * sizeof(int));
    int count = 0;

    // Coletar índices das linhas que passam no filtro
    for (int i = 0; i < csv->num_linhas; i++) {
        if (cumprirFiltro(csv->dados[i][indice], operador, valor)) {
            filtrados[count++] = i;
        }
    }

    // Exibir resultados usando lógica paginada
    if (count > 10) {
        printf("Exibindo as primeiras e últimas 5 entradas de %d resultados:\n", count);
        mostrarDadosFormatadosParcial(csv, filtrados, 5); // Mostrar as primeiras 5
        printf("...\n");
        mostrarDadosFormatadosParcial(csv, filtrados + count - 5, 5); // Mostrar as últimas 5
    } else {
        mostrarDadosFormatadosParcial(csv, filtrados, count); // Mostrar todos os resultados
    }

    free(filtrados);

    char escolha;
    printf("Deseja gravar um arquivo com os dados filtrados? [S|N]: ");
    scanf(" %c", &escolha);
    if (escolha == 'S' || escolha == 's') {
        char nomeArquivo[100];
        printf("Entre com o nome do arquivo: ");
        scanf("%99s", nomeArquivo);
        gravarDadosFiltrados(csv, nomeArquivo);
    }
}

// Função para gravar os dados filtrados
void gravarDadosFiltrados(DadosCSV *csv, const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "w");
    if (!file) {
        printf("Não foi possível criar o arquivo %s\n", nomeArquivo);
        return;
    }
    for (int i = 0; i < csv->num_linhas; i++) {
        for (int j = 0; j < csv->num_colunas; j++) {
            fprintf(file, "%s,", csv->dados[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Arquivo gravado com sucesso: %s\n", nomeArquivo);
}
