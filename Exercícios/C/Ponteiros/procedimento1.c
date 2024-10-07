#include <stdio.h>

void troca(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main(void){
    int a, b; // *ptr1, *ptr2 não precisa de ponteiros auxiliares

    /*
     *   ptr1 = &a;
     *   ptr2 = &b;
     */
    
    printf ("Digite dois valores a serem trocados:\n");
    scanf("%d %d", &a, &b);

    printf ("Valor antes %d %d\n", a, b);
    
    troca(&a, &b);

    printf ("Valor depois %d %d\n", a, b);

    return 0;
}