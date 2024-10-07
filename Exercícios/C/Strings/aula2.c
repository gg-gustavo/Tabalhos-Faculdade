#include <stdio.h>
#include <stdlib.h>

// scanf("%80[^\n]", string); -> isso esta pegando o tamanho máximo da string 80 char e esta ledo ate o [enter]

int main(void){

    char nome[50];
    scanf("%50[^\n]", nome);

    printf("Seu nome eh: %s\n", nome);

    return 0;
}