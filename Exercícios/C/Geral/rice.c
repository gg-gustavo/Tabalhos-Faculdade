#include <stdio.h>

int celulas_necessarias(int graos){
    int cont, x;
    cont = 1;
    x = 1;
    while (x < graos){
        x = x*2;
        cont++;
    }

    return cont;
}   

int main(void){

    int entrada, funcao;
    entrada = 0;

    scanf("%d", &entrada);
    funcao = celulas_necessarias(entrada);
    printf("%d", funcao);

    return 0;
}