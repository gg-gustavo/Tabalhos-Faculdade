#include <stdio.h>
#include <stdlib.h>

void ler_vetor(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}

void imprime_vetor(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void intersecao(int *vet1, int tam1, int *vet2, int tam2, int **res, int *tam_res) {
    int i, j, k = 0;

    // Aloca o máximo possível de espaço para o vetor de interseção
    *res = (int *)malloc(tam1 * sizeof(int));
    if (*res == NULL) {
        printf("Erro ao alocar memória para o resultado.\n");
        exit(1);
    }

    // Encontra a interseção entre os dois vetores
    for (i = 0; i < tam1; i++) {
        for (j = 0; j < tam2; j++) {
            if (vet1[i] == vet2[j]) {
                (*res)[k] = vet1[i]; // Adiciona o elemento comum ao resultado
                k++;
                break; // Evita duplicar elementos na interseção
            }
        }
    }

    // Define o tamanho da interseção
    *tam_res = k;
}

int main(void) {
    int *vetor1, *vetor2, *resultado;
    int tamanho1, tamanho2, tamanho_res;

    // Leitura do tamanho e dos elementos do primeiro vetor
    printf("Digite o tamanho do primeiro vetor:\n");
    scanf("%d", &tamanho1);
    vetor1 = (int *)malloc(tamanho1 * sizeof(int));
    if (vetor1 == NULL) {
        printf("Erro ao alocar memória para o primeiro vetor.\n");
        return 1;
    }
    printf("Digite os elementos do primeiro vetor:\n");
    ler_vetor(vetor1, tamanho1);

    // Leitura do tamanho e dos elementos do segundo vetor
    printf("Digite o tamanho do segundo vetor:\n");
    scanf("%d", &tamanho2);
    vetor2 = (int *)malloc(tamanho2 * sizeof(int));
    if (vetor2 == NULL) {
        printf("Erro ao alocar memória para o segundo vetor.\n");
        free(vetor1); // Libera a memória do primeiro vetor se houver erro
        return 1;
    }
    printf("Digite os elementos do segundo vetor:\n");
    ler_vetor(vetor2, tamanho2);

    // Encontra a interseção dos dois vetores
    intersecao(vetor1, tamanho1, vetor2, tamanho2, &resultado, &tamanho_res);

    // Imprime o vetor de interseção
    printf("Interseção dos vetores:\n");
    if (tamanho_res > 0) {
        imprime_vetor(resultado, tamanho_res);
    } else {
        printf("Nenhuma interseção encontrada.\n");
    }

    // Libera a memória alocada
    free(vetor1);
    free(vetor2);
    free(resultado);

    return 0;
}
