#include <stdio.h>


int palindromo(int *v, int a, int b){
    if (a >= b){  // Caso base: todos os pares foram comparados
        printf("Sim, é palindromo!\n");
        return 1;
    }
    else if(v[a] != v[b]){  // Caso em que os elementos não são iguais
        printf("Não é um palindromo\n");
        return 0;
    }
    else{  // Chamada recursiva
        return palindromo(v, a+1, b-1);
    }
}

int main(void){

    int vet1[5] = {0, 1, 0, 1 ,0};
    int vet2[1] = {69};
    int vet3[6] = {1, 2, 3, 1, 2, 1};

    palindromo(vet1, 0, 4);
    palindromo(vet2, 0, 0);
    palindromo(vet1, 0, 5);

    return 0;
}