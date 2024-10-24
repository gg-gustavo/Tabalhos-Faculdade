#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define  MAX_CHAR 513

char remove_enter(char *str){
    int i = 0;
    while(str[i] != '\n'){
        i++;
    }
    if (str[i] == '\n'){
        str[i] = '\0';
    }
    return *str;
}

void maiusculo(char *str1, char *str2){
    int i = 0;
    while(str1[i] != '\0'){
        str2[i] = toupper(str1[i]);
        i++;
    }
    str2[i] = '\0';
}

void minusculo(char *str1, char *str2){
    int i = 0;
    while(str1[i] != '\0'){
        str2[i] = tolower(str1[i]);
        i++;
    }
    str2[i] = '\0';
}

int main(void){
    char entrada[MAX_CHAR];
    char saida[MAX_CHAR];
    int menu, i;

    printf("Digite a sua frase:\n");
    fgets(entrada, MAX_CHAR, stdin);
    remove_enter(entrada);
    printf("Digite a opção para sua frase:\n");
    printf("SAIR [0]\n");
    printf("MAIUCAULA [1]\n");
    printf("minuscula [2]\n");
    scanf("%d", &menu);

    if (menu == 1){
        maiusculo(entrada, saida);
        printf("%s\n", saida);
    }
    else if (menu == 2){
        minusculo(entrada, saida);
        printf("%s\n", saida);
    }
    else if (menu == 0){
        printf("Saindo...\n");
    }
    
    return 0;
}