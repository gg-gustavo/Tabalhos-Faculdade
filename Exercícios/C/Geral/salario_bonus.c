#include <stdio.h>

int main(void){

    char nome[50];
    scanf("%s", nome);

    double salario, vendas;

    scanf("%lf %lf", &salario, &vendas);
    printf("TOTAL %.2lf\n", salario + vendas * 0.15);


    return 0;
}