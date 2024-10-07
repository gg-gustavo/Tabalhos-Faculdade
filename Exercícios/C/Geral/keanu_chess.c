#include <stdio.h>

int branca(int n){
    if (n%2 == 0){
        return (n*n)/2;
    }
    else{
    return (n*n/2) +1;
    }
}

int preta(int n){
    return (n*n) /2;
}

int main(void){

    int entrada;
    scanf("%d", &entrada);
    printf("%d casas brancas e %d casas pretas\n", branca(entrada), preta(entrada));
    return 0;
    
}