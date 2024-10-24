#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513

char remove_enter(char *valor){
    int i = 0;
    while (valor[i] != '\n'){
        i++;
    }
    if(valor[i] == '\n'){
        valor[i] = '\0';
    }
    return *valor;
}

int main(void){
    char entrada[MAX_CHAR], copia[MAX_CHAR];
    int i, tam, igual = 0;
    printf("Bem vindo ao programa de palavra palindroma:\n");
    printf("Digite a palavra:\n");
    fgets(entrada, MAX_CHAR, stdin);
    remove_enter(entrada);
    tam = strlen(entrada);

    for(i = 0; i < tam; i++){
        copia[i] = entrada[tam -1];
        tam--;
    }
    copia[i] = '\0';

    for (i = 0; i < tam; i++){
        if(copia[i] == entrada[i]){
            igual++;
        }
    }
    if (igual == tam){
        printf("É palindormo!\n");
    }
    else{
        printf("Não é palindromo!\n");
    }
    return 0;
}