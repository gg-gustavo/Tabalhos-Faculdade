#include <stdio.h>

int main(void){

    int *ponteiro, valor;
    valor = 69;

    ponteiro = &valor;


    printf("O valor de ponteiro é %p", ponteiro);
    printf("O valor que o ponteiro aponta é %d\n", *ponteiro);
    
    return 0;
}