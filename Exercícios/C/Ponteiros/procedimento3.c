#include <stdio.h>
#include <stdlib.h>

void ler_vetor(int *vet, int *tam){
    printf("Digite os elementos\n");
    int i;
    for(i = 0; i < *tam; i++){
        scanf("%d", &vet[i]);
    }
}

void imprime_vetor(int *vet, int *tam){
    int i;
    for(i = 0; i < *tam; i++){
        printf("%d ", vet[i]);
    }
}

int main(void){

    int *vetor1, *vetor2, tamanho;


    printf("Digite o tamanho do primeiro vetor:\n");
    scanf("%d", &tamanho);

    vetor1 = (int *)malloc(tamanho * sizeof(int));
    if(vetor1 == NULL){
        printf("erro ao alocar");
        return 1;
    }
    ler_vetor(vetor1, &tamanho);

    printf("\nDigite o tamanho do segundo vetor:\n");
    scanf("%d", &tamanho);

    vetor2 = (int *)malloc(tamanho * sizeof(int));
    if(vetor2 == NULL){
        printf("erro ao alocar");
        return 1;
    }

    ler_vetor(vetor2, &tamanho);
    printf("\n");
    printf("[ ");
    imprime_vetor(vetor1, &tamanho);
    printf("]\n");
    printf("\n");
    printf("\n");
    printf("[ ");
    imprime_vetor(vetor2, &tamanho);
    printf("]\n");

    printf("\n");
    printf("[ ");
    imprime_vetor(vetor1, &tamanho);
    imprime_vetor(vetor2, &tamanho);
    printf("]\n");

    free(vetor1);
    free(vetor2);

    return 0;
}