#include <stdio.h>
#include <math.h> // para usar fabs

double raiz_quadrada(double x, double E, double a, double b){
    
    double m;
    m = (a + b) / 2;
    
    if (fabs(m * m - x) <= E){  // condição de parada
        return m;
    }
    
    if(m * m > x){ // ajusta o intervalo
        return raiz_quadrada(x, E, a, m);
    } else {
        return raiz_quadrada(x, E, m, b);
    }
}

int main(void){
    
    double entrada;

    printf("Escreva um número para calcular a raiz quadrada:\n"); 
    scanf("%lf", &entrada);
    
    if (entrada < 0) {
        printf("Não é possível calcular a raiz quadrada de um número negativo.\n");
        return 1;
    }

    // Chamada da função com o intervalo [1, entrada] para valores maiores que 1
    printf("O valor da raiz quadrada de %.2lf é: %.10lf\n", entrada, raiz_quadrada(entrada, 0.001, 0, entrada + 1));

    return 0;
}