#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513

char remove_enter(char valor[MAX_CHAR]){
    int i = 0;
    while (valor[i] != '\n'){
        i++;
    }
    if (valor[i] == '\n'){
        valor[i] = '\0';
    }
    return *valor;
} 

int main(void){
    char entrada1[MAX_CHAR], entrada2[MAX_CHAR];
    printf("Vamos comparar Strings:\n");
    printf("Digite a primeira Palvra:\n");
    fgets(entrada1, MAX_CHAR, stdin);
    printf("Digite a segunda Palvra:\n");
    fgets(entrada2, MAX_CHAR, stdin);
    remove_enter(entrada1);
    remove_enter(entrada2);

    if (strcmp(entrada1, entrada2) == 0){
        printf("São iguais!\n");
    }
    else{
        printf("São Diferentes\n");
    }

    return 0;
}