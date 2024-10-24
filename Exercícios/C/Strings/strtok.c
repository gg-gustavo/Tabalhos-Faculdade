#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513

char remove_enter(char *valor){
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
    char entrada[MAX_CHAR];
    char *ptr; // para receber a função strtok
    printf("Digite o seu texto:\n");
    fgets(entrada, MAX_CHAR, stdin);
    remove_enter(entrada);
    ptr = strtok(entrada, " ");
    while(ptr){
        printf("\n%s.\n", ptr);
        ptr = strtok(NULL, " ");
    }

    return 0;
}