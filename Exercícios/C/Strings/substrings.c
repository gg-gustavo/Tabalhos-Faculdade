#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513

char remove_caracter(char *valor){
    int i = 0;
    while(valor[i]!= '\n'){
        i++;
    }
    if(valor[i] == '\n'){
    valor[i] = '\0';
    }
    return *valor;
}

int main(void){
    char entrada[MAX_CHAR];
    printf("Digite a palavra:\n");
    fgets(entrada, MAX_CHAR, stdin);
    remove_caracter(entrada);

    printf("%s\n", strstr(entrada, "Ola"));

    return 0;
}