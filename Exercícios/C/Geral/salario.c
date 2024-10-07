#include <stdio.h>

float func_salario(int h, float s){ // hora e salario
    return h*s;
}

int main(void){
    int id, hora;
    float salario;

    scanf("%d %d %f", &id, &hora, &salario);
    printf("NUMBER = %d\nSALARY = U$ %.2f\n", id, func_salario(hora, salario));

    return 0;
}