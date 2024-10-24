#include <stdio.h>

// Ver se o elemento é igual ao índice
int ponto_fixo(int *v, int a, int b){
    int m;
    if (a > b){
        return -1;  // Não existe ponto fixo
    }
    
    m = (a + b) / 2;  // Calcula o índice do meio
    
    if (v[m] == m) {
        return m;  // Encontrou o ponto fixo
    }
    
    // Busca na metade esquerda
    int esquerda = ponto_fixo(v, a, m - 1);
    int direita = ponto_fixo(v, m + 1, b);
    
    if (esquerda != -1) {
        return esquerda;  // Se encontrou o ponto fixo na esquerda
    }
    
    // Se não encontrou na esquerda, busca na direita
    return direita;
}

int main(void){
    int i, tam;
    
    printf("Digite o tamanho do seu vetor:\n");
    scanf("%d", &tam);
    
    int vet[tam];
    
    printf("Digite o seu vetor:\n");
    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }

    // Se o ponto fixo for encontrado, o índice será impresso, caso contrário, imprime que não há ponto fixo
    if(ponto_fixo(vet, 0, tam - 1) == -1){
        printf("Não é ponto Fixo!\n");
    }
    else{
        printf("É ponto Fixo! Cujo indice é: %d\n", ponto_fixo(vet, 0, tam - 1));
    }

    return 0;
}
