#ifndef SELECAO_H
#define SELECAO_H

#include "io.h"  // Inclui o cabeçalho io.h para utilizar a definição de DadosCSV

// Declaração das funções para seleção e gravação de colunas
void selecionarColunas(DadosCSV *csv);  // Permite selecionar colunas específicas de um conjunto de dados CSV
void gravarDadosFiltradosParciais(DadosCSV *csv, const char *nomeArquivo, int *indices, int num_indices); // Grava um arquivo CSV contendo apenas as colunas selecionadas pelos índices fornecidos

#endif
