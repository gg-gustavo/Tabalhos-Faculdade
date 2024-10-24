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
    int tam, i; 

    printf("Qual o tamanho do seu vetor?\n");
    scanf("%d", &tam);
    int vet[tam];
    printf("Digite o seu vetor:\n");

    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }

    troca_elems(vet, 0, tam -1); // c, os indices são indexados de [0..n]

    printf("Vetor invertido:\n");
    for(i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}