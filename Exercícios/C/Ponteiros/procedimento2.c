#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void inverter(int *vetor, int tam){
    
    int inicial, final;
    
    inicial = 0;
    final = tam -1;

    while(final >= inicial){
        troca(&vetor[inicial], &vetor[final]);
        final--;
        inicial++;
    }
    
}

int main(void){

    int *array;
    int i, tamanho;

    printf("Digite o tamanho do vetor\n");
    scanf("%d", &tamanho);
    printf("Digite os elementos:\n");
    
    // alocar dincmicamente

    array = (int *)malloc(tamanho * sizeof(int));

    // testar se existe espaço na memória

    if (array == NULL){
        printf("erro na alocacao");
        return 1;        
    }

    printf("Digite os valores dos elementos:\n");
    for (i = 0; i < tamanho; i++){
        scanf("%d", &array[i]);
    }

    printf("Valor do seu vetor antes é:\n");
    printf("[ ");
    for (i = 0; i < tamanho; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");

    inverter(array, tamanho);

    printf("\nValor do seu vetor depois é:\n");
    printf("[ ");
    for (i = 0; i < tamanho; i++){
        printf("%d ", array[i]);
    }
    printf("]\n");

    free(array);
    return 0;
}