#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513

char remove_enter(char valor[MAX_CHAR]){
    int i = 0;
    while(valor[i] != '\n'){
        i++;
    }
    if(valor[i] == '\n'){
        valor[i] = '\0';
    }
    return *valor;
}

int main(void){
    char entrada1[MAX_CHAR], entrada2[MAX_CHAR];
    printf("Digite a primeira frase: ");
    fgets(entrada1, MAX_CHAR, stdin);
    remove_enter(entrada1);
    printf("Digite a segunda frase: ");
    fgets(entrada2, MAX_CHAR, stdin);
    remove_enter(entrada2);
    strcat(entrada1, " ");
    printf ("A sua frase é: %s", strcat(entrada1, entrada2));
    printf("\n");

    return 0;
}