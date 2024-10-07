#include <stdio.h>

int busca_sequencial(int x, int *v, int a, int b){
    if (a > b || x < v[a]){
        return a -1;
    }
    return busca_sequencial(x, v, a +1, b);
}

int main(void){

    int i, tam, vet[tam], chave;

    printf("Digite o valor do tamanho do vetor:\n");
    scanf("%d", &tam);

    printf("Digite os elementos:\n");
    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }

    printf("Digite o valor da chave:\n");
    scanf("%d", &chave);

    if (busca_sequencial(chave, vet, 0, tam) < 0){
        printf("A sua chave não está no vetor\n");
    }
    else{
        printf("a sua chave esta no indice %d\n", busca_sequencial(chave, vet, 0, tam));
    }


    return 0;
}