#include <stdio.h>

int indice(int *vet, int ini, int tam){
    if (ini  == tam){
        return ini;
    }
    printf(" (%d)x^%d", vet[ini], ini);
    return 1 + indice(vet, ini +1, tam);
}

int main(void){

    int i, tam;
    int vetor1[tam];
    
    printf("Digite o tamanho do vetor\n");
    scanf("%d", &tam);
    
    printf("Digite o vetor: ");
    for(i = 0; i < tam; i++){
        scanf("%d", &vetor1[i]);
    }

    printf("O seu plinômio é: ");
    indice(vetor1, 0, tam);
    printf("\n");


    return 0;
}