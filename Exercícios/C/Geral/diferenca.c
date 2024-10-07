#include <stdio.h>

int diferenca(int a, int b, int c, int d){

    return a*b-c*d;
}

int main(void){

    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("DIFERENCA = %d\n", diferenca(A, B, C, D));

    return 0;
}