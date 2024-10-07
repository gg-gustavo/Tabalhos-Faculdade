#include <stdio.h>
#define PI 3.14159;
 
double area_circ(double raio){
    return raio*raio*PI; 
}

int main(void){
 double entrada, area;
 scanf("%lf", &entrada);
 
 area = area_circ(entrada);

 printf("A=%.4lf\n", area);
    return 0;
}