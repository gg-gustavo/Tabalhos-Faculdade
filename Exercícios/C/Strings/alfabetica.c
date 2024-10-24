#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 513  // Máximo de caracteres por linha
#define MAX_WORDS 100 // Máximo de palavras

// Função para remover o caractere de nova linha (\n) do final da string
void remove_enter(char *valor) {
    int i = 0;
    while (valor[i] != '\n' && valor[i] != '\0') {
        i++;
    }
    if (valor[i] == '\n') {
        valor[i] = '\0';
    }
}

// Função para trocar duas strings no array
void swap(char *str1, char *str2) {
    char temp[MAX_CHAR];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int main(void) {
    char linha[MAX_CHAR];           // Para armazenar a linha de entrada
    char *palavras[MAX_WORDS];       // Array de ponteiros para armazenar as palavras
    int num_palavras = 0;            // Contador para o número de palavras
    char *token;

    // Entrada de dados
    printf("Digite uma linha de palavras:\n");
    fgets(linha, MAX_CHAR, stdin);
    remove_enter(linha);  // Remove o '\n' se estiver presente

    // Usa strtok para dividir a linha em palavras com base nos espaços
    token = strtok(linha, " ");
    while (token != NULL) {
        palavras[num_palavras] = malloc(strlen(token) + 1); // Aloca memória para cada palavra
        strcpy(palavras[num_palavras], token);  // Copia a palavra para o array
        num_palavras++;  // Incrementa o número de palavras
        token = strtok(NULL, " ");  // Pega a próxima palavra
    }

    // Ordenação das palavras usando Bubble Sort
    for (int i = 0; i < num_palavras - 1; i++) {
        for (int j = 0; j < num_palavras - i - 1; j++) {
            if (strcmp(palavras[j], palavras[j + 1]) > 0) {
                swap(palavras[j], palavras[j + 1]);  // Troca se estiver fora de ordem
            }
        }
    }

    // Exibe as palavras ordenadas
    printf("\nPalavras em ordem alfabética:\n");
    for (int i = 0; i < num_palavras; i++) {
        printf("%s\n", palavras[i]);
        free(palavras[i]);  // Libera a memória alocada para cada palavra
    }

    return 0;
}
