#include <stdio.h>
#include <string.h>
#define MAX_CHAR 513 //512 + 1 (buffer '\n')

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
    char entrada[MAX_CHAR], copia[MAX_CHAR];
    int i, tam, diferente = 0, j = 0;
    printf("Digite a sua frase para ver se é ou não um palíndromo:\n");
    fgets(entrada, MAX_CHAR, stdin);
    remove_enter(entrada);
    tam = strlen(entrada);
    for(i = 0; i < tam; i++){
        if(entrada[i] != '.' && entrada[i] != ' ' && entrada[i] != ',' && entrada[i] != '!' && entrada[i] != '?'){
            copia[j] = entrada[i];
            j++;
        }
    }

    tam = strlen(copia);
    for(i = 0; i < tam; i++){
        if(copia[i] != copia[tam-1]){
            diferente++; // se for igual a zero significa que todas as strings são igauis
        }
        tam--;
    }

    if(diferente == 0){
        printf("É palindromo!\n");
    }
    else{
        printf("Não é palindromo!\n");
    }

    return 0;
}