#include <stdio.h>

int fibonacci(int n){
    if (n <= 1){
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void){
    int valor;
    printf("Digite um valor para saber qual e a posição da sequencia de FIBONACCI:\n");
    scanf("%d", &valor);
    printf("O valor da poisicao %d eh %d\n", valor, fibonacci(valor));

    return 0;
}