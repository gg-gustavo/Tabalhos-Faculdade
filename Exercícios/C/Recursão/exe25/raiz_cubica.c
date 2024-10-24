#include <stdio.h>
#include <math.h>

double raiz_cubica(double x, double E, double a, double b){ // x = elemento de radio fds, E = Epsilon, a = inicial, b = final
    double m; //rachando o intervalo n a metade
    m = (a + b) /2;
    if(fabs(m * m * m - x) <= E){
        return m;
    }
    if(m * m * m > x){
        return raiz_cubica(x, E, a, m);
    }
    return raiz_cubica(x, E, m, b);
}

int main(void){

    double entrada;

    printf("Escreva um número para calcular a raiz Cubica:\n"); 
    scanf("%lf", &entrada);
    
    if (entrada < 0) {
        printf("Não é possível calcular a raiz Cubica de um número negativo.\n");
        return 1;
    }

    // Chamada da função com o intervalo [1, entrada] para valores maiores que 1
    printf("O valor da raiz quadrada de %.2lf é: %.10lf\n", entrada, raiz_cubica(entrada, 0.001, 0, entrada + 1));

    return 0;
}