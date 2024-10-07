#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ler_string(char **entrada, int tamanho){
   *entrada = (char *)malloc(tamanho * sizeof(char));
    if(*entrada != NULL){
    fgets(*entrada, tamanho, stdin);

    (*entrada)[strcspn(*entrada, "\n")] = '\0'; //remove o \n da funcao fgets()
    }
}

void imprime_string(char *entrada){
    puts(entrada);
}


int main(void){
    int tam = 50;
    char *nome, *sobrenome, *completo;

    ler_string(&nome, tam);
    ler_string(&sobrenome, tam);

    completo = (char *)malloc((tam*2) * sizeof(char));
    if(completo != NULL){
    
    //copiar o nome para completo
    strcpy(completo, nome);
    strcat(completo, " ");
    strcat(completo, sobrenome);
    
    }

    imprime_string(completo);
    
    printf("o tamanho da string é %ld\n", strlen(completo));
    
    free(nome);
    free(sobrenome);
    free(completo);
    return 0;
}