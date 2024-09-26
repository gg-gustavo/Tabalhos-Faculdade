#ifndef ORDENA_H
#define ORDENA_H

#include "io.h"

int comparar_qsort(const void *a, const void *b);  // Função de comparação para qsort
int encontrarIndiceColuna_qsort(DadosCSV *csv, const char *nomeColuna);  // Encontra o índice de uma coluna pelo nome
void ordenarDados(DadosCSV *csv, const char *nomeColuna, char ordem);  // Ordena os dados CSV
void gravarDadosOrdenados(DadosCSV *csv, const char *nomeArquivo);  // Grava os dados ordenados em um arquivo CSV

#endif
