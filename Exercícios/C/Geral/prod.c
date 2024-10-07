#include <stdio.h>

int produto(int a, int b){
    return a * b;
}

int main(void){

    int A, B, PROD;

    scanf("%d %d", &A, &B);
    PROD = produto(A, B);
    printf("PROD = %d\n", PROD);

    return 0;
}