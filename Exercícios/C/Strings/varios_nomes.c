#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler_string(char **entrada, int tamanho) {
    // Alocar dinamicamente
    *entrada = (char *)malloc(tamanho * sizeof(char));
    if (*entrada != NULL) {
        fgets(*entrada, tamanho, stdin);
        (*entrada)[strcspn(*entrada, "\n")] = '\0'; // Remove o \n da função fgets
    }
}

void imprime_string(char **entrada, int n_strings) {
    int i;
    for (i = 0; i < n_strings; i++) {
        printf("String %d: %s (Tamanho: %ld)\n", i + 1, entrada[i], strlen(entrada[i]));
    }
}

int main(void) {
    int num_strings, i, tam = 100;
    char **string;

    // Perguntar quantas strings deseja inserir
    printf("Quantas strings deseja inserir?\n");
    scanf("%d", &num_strings);
    getchar(); // Captura o \n do scanf

    // Alocar memória para o array de ponteiros de strings
    string = (char **)malloc(num_strings * sizeof(char *));
    if (string == NULL) {
        printf("Erro ao alocar memória para o array de strings.\n");
        return 1;
    }

    // Armazenar o array de strings
    for (i = 0; i < num_strings; i++) {
        printf("Digite a string %d: ", i + 1);
        ler_string(&string[i], tam);
    }

    // Imprimir as strings
    imprime_string(string, num_strings);

    // Liberar memória alocada
    for (i = 0; i < num_strings; i++) {
        free(string[i]);
    }
    free(string);

    return 0;
}
