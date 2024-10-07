#include <stdio.h>

int ocorrencia(int *v, int a, int b, int x){ // vetor, indice inicial, indice final, chave
    if (b < a){
        return 0;
        }
    if (x == v[b]){
        return 1 + ocorrencia(v, a, b-1, x);
    }
    return ocorrencia(v, a, b-1, x);
}

int main(void){

    int i, tam, vet[tam], chave;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &tam);

    printf("Digite os elementos:\n");
    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }

    printf("Digite a chave:\n");
    scanf("%d", &chave);

    printf("O valor ocorrencias foi de: %d\n", ocorrencia(vet, 0, tam, chave));
    
    return 0;
}