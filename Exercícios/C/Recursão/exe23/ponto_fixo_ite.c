#include <stdio.h>

int ponto_fixo_ite(int *v, int a, int b){
    int m;
    while (a <= b){

        m = (a + b) /2;
        if (m == v[m]){
        return m; // encontrou ponto fixo
        }
        if (v[m] > m){
            b = m -1; //metade esquerda
        }
        else{
            a = m + 1; //metade direita
        }
    }
    return -1; // Não existe ponto fixo
}

int main(void){

    return 0;
}