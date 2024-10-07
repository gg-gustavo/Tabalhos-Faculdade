#include <stdio.h>

double media_pond(double n1, double n2, double n3){
    n1 = n1*2;
    n2 = n2*3;
    n3 = n3*5;

    return (n1+n2+n3) / (2 + 3 + 5);

}


int main(void){

    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);
    printf("MEDIA = %.1lf\n", media_pond(A, B, C));

    
    return 0;
}