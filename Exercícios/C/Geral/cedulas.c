#include <stdio.h>

int garoupa(int n){ // 100
    return n/100;
}

int onca(int n){ // 50
    n = (n%100)/50;
    return n;
}

int mico(int n){ // 20
    n = ((n%100)%50)/20;
    return n;
}

int arara(int n){ // 10
    n = (((n%100)%50)%20)/10;
    return n;
}

int flamingo(int n){ // 5
    n = ((n%100)%10)/5;
    return n;
}

int tartaruga(int n){ // 2
    n = (((n%100)%10)%5)/2;
    return n;
}

int beija_flor(int n){ // 1
    n = (((n%100)%10)%5)%2;
    return n;
}

int main(void){

    long entrada;
    int cem, cinquenta, vinte, dez, cinco, dois, um;

    scanf ("%ld", &entrada);

    cem = garoupa(entrada); 
    cinquenta = onca(entrada);
    vinte = mico(entrada);
    dez = arara(entrada);
    cinco = flamingo(entrada);
    dois = tartaruga(entrada);
    um = beija_flor(entrada);
    printf("%d\n", entrada);
    printf("%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", cem, cinquenta, vinte, dez, cinco, dois, um);
    return 0;
}