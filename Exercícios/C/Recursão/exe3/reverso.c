#include <stdio.h>

void troca(int *vetor, int x, int y){
    int aux;
    aux = vetor[x];
    vetor[x] = vetor[y];
    vetor[y] = aux;
}

int troca_elems(int *vetor, int a, int b){
    if(b < a){
        return a;
    }
    troca(vetor, a, b);
    return troca_elems(vetor, a+1, b-1);
}

int main(void){
    int i, vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Antes: ");
    for(i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }

    troca_elems(vet, 0, 9);

    printf("\nDepois: ");
    for(i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}