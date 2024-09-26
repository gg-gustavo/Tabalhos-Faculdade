#ifndef DESCRICAO_H
#define DESCRICAO_H

#include "io.h"  // Inclui o cabeçalho io.h para usar a definição de DadosCSV

// Definição da estrutura FrequenciaValor para armazenar um valor e sua frequência
typedef struct {
    char* valor;
    int frequencia;
} FrequenciaValor;

// Declarações das funções para cálculo e descrição estatística de variáveis numéricas
double calcularMedia(double *valores, int tamanho);  // Calcula a média de um array de valores
double calcularMediana(double *valores, int tamanho);  // Calcula a mediana de um array de valores
void calcularEImprimirModa(double *valores, int tamanho);  // Calcula e imprime a moda de um array de valores
double calcularDesvioPadrao(double *valores, int tamanho, double media);  // Calcula o desvio padrão de um array de valores
double encontrarMinimo(double *valores, int tamanho);  // Encontra o valor mínimo em um array de valores
void imprimirValoresUnicos(double *valores, int tamanho);  // Imprime os valores únicos em um array de valores
int encontrarIndiceDaColuna(DadosCSV *csv, const char *nomeColuna);  // Encontra o índice de uma coluna no conjunto de dados CSV
int comparar(const void *a, const void *b);  // Função de comparação para usar com qsort

// Declarações das funções para descrição de variáveis numéricas e categóricas
void descreverVariavelNumerica(DadosCSV *csv, const char *nomeColuna);  // Descreve estatísticas de uma variável numérica
void descreverVariavelCategorica(DadosCSV *csv, const char *nomeColuna);  // Descreve estatísticas de uma variável categórica

#endif
