#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513 //  POR (512 +1) CONTA DO FIM DE STRING

int main(void){

    char palavra[MAX_CHAR];

    printf("Digite seu nome\n");
    fgets(palavra, MAX_CHAR, stdin);
    
    printf("Seu nome é %s:", palavra);

    return 0;
}