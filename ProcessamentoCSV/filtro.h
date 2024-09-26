#ifndef FILTRO_H
#define FILTRO_H

#include "io.h"

// Declaração das funções do filtro

void aplicarFiltro(DadosCSV *csv); // Aplica um filtro aos dados CSV
void gravarDadosFiltrados(DadosCSV *csv, const char *nomeArquivo); // Grava os dados filtrados em um arquivo
int encontrarIndiceDaColuna(DadosCSV *csv, const char *nomeColuna); // Encontra o índice da coluna com o nome especificado
void mostrarDadosFormatadosParcial(DadosCSV *csv, int *indices, int num_indices); // Mostra os dados formatados parcialmente

#endif
