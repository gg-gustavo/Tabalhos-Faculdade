#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513

// Função para remover o caractere de nova linha (\n) do final da string
char remove_enter(char *valor) {
    int i = 0;
    while (valor[i] != '\n' && valor[i] != '\0') {  // Verifica também se é o fim da string
        i++;
    }
    if (valor[i] == '\n') {
        valor[i] = '\0';  // Substitui o '\n' por '\0'
    }
    return *valor;
}

int main(void) {
    char entrada[MAX_CHAR], copia[MAX_CHAR];
    int i = 0, j, tam;

    // Entrada de dados
    printf("Inversor de Strings:\n");
    printf("Digite a sua palavra:\n");
    fgets(entrada, MAX_CHAR, stdin);  // Leitura da entrada com fgets, protegendo o buffer
    remove_enter(entrada);  // Remove o '\n' da string de entrada, se presente

    tam = strlen(entrada);  // Obtém o tamanho da string
    if (tam > 0) {  // Verifica se a string tem conteúdo
        j = tam - 1;  // Inicializa j como o índice do último caractere de entrada

        // Loop para inverter a string usando while
        while (j >= 0) {
            copia[i] = entrada[j];  // Atribui os caracteres da string original na ordem inversa
            i++;  // Avança na cópia
            j--;  // Retrocede na entrada
        }
        copia[i] = '\0';  // Finaliza a string com o caractere nulo

        // Exibe a string invertida
        printf("%s\n", copia);
    } else {
        printf("Entrada vazia ou inválida!\n");
    }

    return 0;
}
