#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513

int main(void){
    int i = 0, tam = -1;
    char entrada[MAX_CHAR];
    printf("Escreva uma Frase, vou contar o tamnaho da String:\n");
    fgets(entrada, MAX_CHAR, stdin);
    
    while (entrada[i] != '\0'){
        i++;
        tam++;
    }
    
    printf("\nO tamanho da Frase: %s\nÉ: %d\n", entrada, tam);

    return 0;
}