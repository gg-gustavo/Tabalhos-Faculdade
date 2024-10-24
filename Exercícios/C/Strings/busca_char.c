#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513

/*  Qual a diferença:
 *  strchr -> retorna a primeira ocorrência
 *  strrchr -> retorna a ultima ocorrência
 */ 

char remove_caractere(char *vetor){
    int i = 0;
    while(vetor[i] != '\n'){
        i++;
    }
    if(vetor[i] == '\n'){
        vetor[i] = '\0';
    }
    return *vetor;
}

int main(void){
    char entrada[MAX_CHAR];
    printf("Digite a sua frase:\n");
    fgets(entrada, MAX_CHAR, stdin);
    remove_caractere(entrada);

    char *letra;
    letra = strchr(entrada, 'a');
    printf("\n%c\n", *letra);
    return 0;
}