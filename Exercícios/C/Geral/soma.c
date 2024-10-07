#include <stdio.h>
 
 int soma(int a, int b){
    return a+b;
 }
 
int main(void){

    int A, B, X;

    scanf("%d %d", &A, &B);
    X = soma(A, B);

printf("X = %d", X);
 
    return 0;
}