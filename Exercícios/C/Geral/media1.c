#include <stdio.h>

double media_pond(double n1, double n2){
    
    n1 = n1*3.5;
    n2 = n2*7.5;

    return (n1+n2) / (3.5+7.5);
}

int main(void){
    double A, B;

    scanf("%lf %lf", &A, &B);
    printf("MEDIA = %.5lf\n", media_pond(A, B));

    return 0;
}