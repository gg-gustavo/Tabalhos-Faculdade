#include <stdio.h>
#define PI 3.14159

double esfera(double r){
    return ((4.0/3.0) * PI * (r*r*r));
}

int main(void){
    
    double entrada;

    scanf("%lf", &entrada);
    printf("VOLUME = %.3lf\n", esfera(entrada));
    return 0;
}