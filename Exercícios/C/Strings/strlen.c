#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513

int main (void){
    char entrada[MAX_CHAR];
    printf("Digite uma frase, iriei printar o tamanho da String\n");
    fgets(entrada, MAX_CHAR, stdin);
    printf("O tamanho da frase é: %ld\n", strlen(entrada));
    return 0;

}