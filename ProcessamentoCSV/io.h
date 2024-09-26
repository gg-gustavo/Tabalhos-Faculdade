#ifndef IO_H
#define IO_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 1024
#define MAX_COLUMNS 100

// Estrutura para armazenar dados de um arquivo CSV
typedef struct DadosCSV {
    char **cabecalhos;   // Array de strings para os cabeçalhos das colunas
    char ***dados;       // Matriz de strings para armazenar os dados
    int num_linhas;      // Número de linhas (registros) no CSV
    int num_colunas;     // Número de colunas (campos) no CSV
    char *tipo_coluna;   // Array de caracteres para indicar o tipo de cada coluna ('S' ou 'N')
} DadosCSV;

// Função para ler um arquivo CSV e retornar a estrutura de dados correspondente
DadosCSV *lerCSV(const char *nome_arquivo);

// Função para converter uma string em um caractere
char converteNumero(char *str);

// Função para verificar se uma string contém caracteres acentuados
int temAcento(char *str);

// Função para liberar a memória alocada para a estrutura de dados CSV
void liberarDadosCSV(DadosCSV *csv);

// Função para imprimir um intervalo de linhas formatadas da estrutura de dados CSV
void imprimirLinhas(DadosCSV *csv, int inicio, int fim, int *comprimentos_maximos);

// Função para mostrar um resumo estatístico dos dados CSV
void mostrarResumo(DadosCSV *csv);

// Função para mostrar os dados formatados da estrutura de dados CSV
void mostrarDadosFormatados(DadosCSV *csv);

// Função para encontrar o índice de uma coluna pelo nome
int encontrarIndiceDaColuna(DadosCSV *csv, const char *nomeColuna);

#endif  
