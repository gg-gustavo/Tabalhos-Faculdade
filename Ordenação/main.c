#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void preencheVetorAleatorio(int *vetor, size_t tamanho, int min, int max) {
    srand((unsigned)time(NULL)); // Inicializa o gerador de números aleatórios
    for (size_t i = 0; i < tamanho; i++) {
        vetor[i] = min + rand() % (max - min + 1);
    }
}

int main() {
    char nome[MAX_CHAR_NOME];
    getNome(nome);
    uint64_t numComp;
    ssize_t idxBusca;
    int chave, escolha, escolhaAlgoritmo, escolhaVersao, desejaPrintar, continuar;
    size_t tamVetor;

    printf("\nTRABALHO 1 ALGORITMOS E ESTRUTURA DE DADOS 2:\n");
    printf("\nNome: %s\n", nome);
    printf("GRR: %u\n\n", getGRR());

    printf("Insira um tamanho de vetor de inteiros: ");
    scanf("%zu", &tamVetor);

    int* vetor = (int*)malloc(tamVetor * sizeof(int));
    if (!vetor) {
        printf("Falha ao alocar memória.\n");
        return 1;
    }
    preencheVetorAleatorio(vetor, tamVetor, 1, 10000);

    printf("Deseja printar o vetor na tela?\n(1)SIM\n(2)NAO\n(0)SAIR\n");
    scanf("%d", &desejaPrintar);
    if (desejaPrintar == 1) {
        for (size_t i = 0; i < tamVetor; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");
    } else if (desejaPrintar == 0) {
        free(vetor);
        return 0;
    }

    printf("O que você deseja fazer?\n(1) Ordenar\n(2) Buscar elemento\n(0) SAIR\n");
    scanf("%d", &escolha);

    clock_t start, end;
    double total;

    if (escolha == 1) {
        printf("Qual Algoritmo de ordenação você deseja utilizar?\n(1) Selection Sort\n(2) Insertion Sort\n(3) Merge Sort\n(0) SAIR\n");
        scanf("%d", &escolhaAlgoritmo);

        if (escolhaAlgoritmo == 3) {  // Merge Sort é sempre recursivo
            start = clock();
            numComp = mergeSortRec(vetor, tamVetor);
            end = clock();
        } else if (escolhaAlgoritmo == 1 || escolhaAlgoritmo == 2) {
            printf("Qual versão do Algoritmo você deseja utilizar?\n(1) Recursivo\n(2) Iterativo\n");
            scanf("%d", &escolhaVersao);

            start = clock();
            if (escolhaAlgoritmo == 1) {
                numComp = (escolhaVersao == 1) ? selectionSortRec(vetor, tamVetor) : selectionSort(vetor, tamVetor);
            } else if (escolhaAlgoritmo == 2) {
                numComp = (escolhaVersao == 1) ? insertionSortRec(vetor, tamVetor) : insertionSort(vetor, tamVetor);
            }
            end = clock();
        }

        total = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Operação concluída em %f segundos com %lu comparações.\n", total, numComp);

        printf("Deseja printar o vetor ordenado na tela?\n(1)SIM\n(2)NAO\n(0)SAIR\n");
        scanf("%d", &desejaPrintar);
        if (desejaPrintar == 1) {
            for (size_t i = 0; i < tamVetor; i++) {
                printf("%d ", vetor[i]);
            }
            printf("\n");
        } else if (desejaPrintar == 0) {
            free(vetor);
            return 0;
        }

        printf("Deseja fazer uma busca no vetor ou encerrar o programa?\n(1) Buscar\n(0) Sair\n");
        scanf("%d", &continuar);
        if (continuar == 0) {
            free(vetor);
            return 0;
        } else {
            escolha = 2; // Passar diretamente para busca
        }
    }

    if (escolha == 2) {
        printf("Digite o valor da chave que deseja buscar: ");
        scanf("%d", &chave);
        printf("Qual método de busca você deseja utilizar?\n(1) Busca Binária (Apenas para vetores ordenados)\n(2) Busca Sequencial\n");
        scanf("%d", &escolhaAlgoritmo);
        
        if (escolhaAlgoritmo == 1 || escolhaAlgoritmo == 2) {
            printf("Qual versão do método você deseja utilizar?\n(1) Recursivo\n(2) Iterativo\n");
            scanf("%d", &escolhaVersao);
        }

        start = clock();
        if (escolhaAlgoritmo == 1) {
            idxBusca = (escolhaVersao == 1) ? buscaBinariaRec(vetor, tamVetor, chave, &numComp) : buscaBinaria(vetor, tamVetor, chave, &numComp);
        } else if (escolhaAlgoritmo == 2) {
            idxBusca = (escolhaVersao == 1) ? buscaSequencialRec(vetor, tamVetor, chave, &numComp) : buscaSequencial(vetor, tamVetor, chave, &numComp);
        }
        end = clock();

        total = ((double)(end - start)) / CLOCKS_PER_SEC;
        if (idxBusca != -1) {
            printf("Chave %d encontrada na posição: %zd, com %lu comparações, em %f segundos.\n", chave, idxBusca, numComp, total);
        } else {
            printf("Chave %d não encontrada, com %lu comparações, em %f segundos.\n", chave, numComp, total);
        }
    }

    free(vetor);
    return 0;
}
