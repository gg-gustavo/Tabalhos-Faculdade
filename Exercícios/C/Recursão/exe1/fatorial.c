#include <stdio.h>

int fatorial(int n){
    if (n == 1 || n == 0){
        return 1;
    }
    else if(n < 0){
        printf("Digite um valor inteiro e positivo!\n");
    }
    else{
        return (n * fatorial(n-1));
    }

}

int main(void){
    int teste;
    scanf("%d", &teste);
    if (teste < 0){
        printf("Instancia Inválida!\n");
    }
    else{
        fatorial(teste);
        printf("O valor do fatorial eh: %d\nFim do programa\n", fatorial(teste));
    }
    return 0;
}