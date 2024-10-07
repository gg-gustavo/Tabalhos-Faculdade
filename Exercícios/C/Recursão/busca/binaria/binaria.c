#include <stdio.h>

int busca_binaria(int x, int *v, int a, int b){
    int m; //meio
    if(a > b){
        return a -1;
    }
    m = (a + b)/2;
    if(x < v[m]){
        return busca_binaria(x, v, a, m -1);
        return busca_binaria(x, v, m +1, b);
    }
}

int main(void){

    int i, tam, vet[tam], chave;

    printf("Digite o tamanho no seu vetor:\n");
    scanf("%d", &tam);

    printf("Digite os elementos:\n");
    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }
    
    printf("Digite o valor da chave:\n");
    scanf("%d", &chave);

    if(busca_binaria(chave, vet, 0, tam) < 0){
        printf("A cahve não está no vetor\n");
    }
    else{
        printf("A chave está no indice %d\n", busca_binaria(chave, vet, 0, tam));
    }

    return 0;
}