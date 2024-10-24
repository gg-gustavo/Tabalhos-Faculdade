#include <stdio.h>

int hanoi(int n, int A, int B, int C){
    if( n <= 1){
        return n;
    }
    return hanoi(n-1, A, C, B);

    return hanoi(n-1, C, B, A);
}

int main(void){
    int entrada;
    printf("Algoritmo de Torre de Hanoi:\n");
    printf("Digite o número de Discos:\n");
    scanf("%d", &entrada);
    printf ("Núemro de movimentos foram de: %d\n", hanoi(entrada, entrada, 0, 0));

    return 0;
}