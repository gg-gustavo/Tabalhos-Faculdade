#ifndef FALTANTES_H
#define FALTANTES_H

#include "io.h"  // Inclui o cabeçalho io.h para usar a definição de DadosCSV

// Declaração das funções para tratamento de dados faltantes
void listarNaN(DadosCSV *csv);  // Lista linhas com valores "NaN" no CSV
void substituirPorMedia(DadosCSV *csv);  // Substitui valores "NaN" pela média dos valores válidos na mesma coluna
void substituirProximoValido(DadosCSV *csv);  // Substitui valores "NaN" pelo próximo valor válido na mesma coluna
void removerNaN(DadosCSV *csv);  // Remove linhas do CSV que contenham valores "NaN"
void tratarDadosFaltantes(DadosCSV *csv);  // Função principal para tratamento interativo de dados faltantes

#endif
