#include "ordenacao.h"
#include <stdlib.h>  
#include <string.h>

// Preenche o nome fornecido com um valor fixo
void getNome(char nome[]) {
    strncpy(nome, "Gustavo Gabriel Ripka", MAX_CHAR_NOME); // Copia o nome para a variável nome
    nome[MAX_CHAR_NOME - 1] = '\0'; // Garante que a string tenha terminação nula
}

// Retorna um número GRR fixo
uint32_t getGRR() {
    return 20203935; 
}

// Função para trocar dois elementos de lugar
void troca(int *a, int *b) {
    int temp = *a; // Guarda o valor de a temporariamente
    *a = *b; 
    *b = temp; 
}

// Realiza uma busca sequencial em um vetor
ssize_t buscaSequencial(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    *numComparacoes = 0; // Inicializa o contador de comparações
    for (size_t i = 0; i < tam; i++) {
        (*numComparacoes)++; 
        if (vetor[i] == valor) {
            return i; // Retorna o índice se o valor for encontrado
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado
}

// Realiza uma busca sequencial recursiva
ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    if (tam == 0) {
        *numComparacoes = 0; // Não há comparações se o vetor está vazio
        return -1; // Retorna -1 se o vetor está vazio
    }
    (*numComparacoes)++; // Conta esta comparação
    if (vetor[0] == valor) {
        return 0; // Retorna o índice 0 se o primeiro elemento é o valor
    } else {
        ssize_t result = buscaSequencialRec(vetor + 1, tam - 1, valor, numComparacoes);
        return result == -1 ? -1 : 1 + result; // Ajusta o índice retornado ou retorna -1 se não encontrado
    }
}

// Função auxiliar para a busca binária recursiva
ssize_t buscaBinariaRecAux(int vetor[], size_t inicio, size_t fim, int valor, uint64_t* numComparacoes) {
    if (inicio > fim) {
        return -1; // Caso base: elemento não encontrado
    }

    size_t meio = inicio + (fim - inicio) / 2;
    (*numComparacoes)++; // Contabiliza a comparação

    if (vetor[meio] == valor) {
        return meio; // Elemento encontrado
    } else if (vetor[meio] > valor) {
        return buscaBinariaRecAux(vetor, inicio, meio - 1, valor, numComparacoes); // Busca na metade esquerda
    } else {
        return buscaBinariaRecAux(vetor, meio + 1, fim, valor, numComparacoes); // Busca na metade direita
    }
}

// Função pública que inicializa a busca binária recursiva
ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    *numComparacoes = 0; // Inicializa o contador de comparações
    return buscaBinariaRecAux(vetor, 0, tam - 1, valor, numComparacoes); // Chama a função auxiliar
}
// Realiza uma busca binária em um vetor
ssize_t buscaBinaria(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    size_t inicio = 0, fim = tam - 1;
    *numComparacoes = 0; // Inicializa o contador de comparações
    while (inicio <= fim) {
        size_t meio = inicio + (fim - inicio) / 2; // Calcula o meio do vetor
        (*numComparacoes)++; 
        if (vetor[meio] == valor) {
            return meio; // Retorna o meio se o valor for encontrado
        } else if (vetor[meio] < valor) {
            inicio = meio + 1; // Ajusta o limite inferior
        } else {
            fim = meio - 1; // Ajusta o limite superior
        }
    }
    return -1; // Retorna -1 se o valor não for encontrado
}

// Insere um elemento na posição correta dentro do vetor para manter a ordenação
void Insere(int vetor[], size_t b, uint64_t* numComparacoes) {
    int p = vetor[b - 1]; // Pega o elemento a ser inserido
    ssize_t i = b - 2; // Começa a verificar a partir do elemento antes do elemento a ser inserido
    while (i >= 0 && vetor[i] > p) { // Enquanto não chegar ao início do vetor e o elemento atual for maior que p
        vetor[i + 1] = vetor[i]; // Desloca o elemento uma posição para frente
        i--; 
        (*numComparacoes)++; 
    }
    vetor[i + 1] = p; // Insere o elemento na posição correta
}

// Ordenação por inserção iterativa
uint64_t insertionSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0; // Contador de comparações
    for (size_t b = 2; b <= tam; b++) {
        Insere(vetor, b, &numComparacoes); // Insere elemento por elemento
    }
    return numComparacoes; // Retorna o número total de comparações
}

// Auxiliar para ordenação por inserção recursiva
void insertionSortRecAux(int vetor[], size_t b, uint64_t* numComparacoes) {
    if (b <= 1) return; // Base da recursão: se o tamanho é 1, está ordenado
    insertionSortRecAux(vetor, b - 1, numComparacoes); // Ordena os primeiros b-1 elementos
    Insere(vetor, b, numComparacoes); // Insere o elemento na posição correta
}

// Ordenação por inserção recursiva
uint64_t insertionSortRec(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0; 
    insertionSortRecAux(vetor, tam, &numComparacoes); // Chama a função auxiliar
    return numComparacoes; 
}

// Ordenação por seleção iterativa
uint64_t selectionSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0; 
    for (size_t i = 0; i < tam - 1; i++) {
        size_t min_idx = i; // Assume que o primeiro elemento é o mínimo
        for (size_t j = i + 1; j < tam; j++) { // Procura o mínimo no restante do vetor
            numComparacoes++; 
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j; // Atualiza o índice do mínimo
            }
        }
        if (min_idx != i) {
            troca(&vetor[i], &vetor[min_idx]); // Troca o mínimo encontrado com o primeiro elemento
        }
    }
    return numComparacoes; // Retorna o número total de comparações
}

// Auxiliar para ordenação por seleção recursiva
void selectionSortRecAux(int vetor[], size_t inicio, size_t tam, uint64_t* numComparacoes) {
    if (inicio >= tam - 1) return; // Base da recursão: se chegou ao último elemento

    size_t min_idx = inicio; // Assume que o elemento inicial é o mínimo
    for (size_t i = inicio + 1; i < tam; i++) {
        (*numComparacoes)++; 
        if (vetor[i] < vetor[min_idx]) {
            min_idx = i; // Atualiza o índice do mínimo
        }
    }

    if (min_idx != inicio) {
        troca(&vetor[inicio], &vetor[min_idx]); // Troca o mínimo encontrado com o elemento inicial
    }

    selectionSortRecAux(vetor, inicio + 1, tam, numComparacoes); // Recursivamente ordena o resto do vetor
}

// Ordenação por seleção recursiva
uint64_t selectionSortRec(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0; // Contador de comparações
    selectionSortRecAux(vetor, 0, tam, &numComparacoes); 
    return numComparacoes; 
}

// Intercala duas metades de um vetor
void merge(int vetor[], int temp_ESQ[], int temp_DIR[], size_t esq, size_t meio, size_t dir, uint64_t* numComparacoes) {
    size_t n1 = meio - esq + 1; // Número de elementos na primeira metade
    size_t n2 = dir - meio; // Número de elementos na segunda metade

    // Copia os dados para arrays temporários
    for (size_t i = 0; i < n1; i++)
        temp_ESQ[i] = vetor[esq + i];
    for (size_t j = 0; j < n2; j++)
        temp_DIR[j] = vetor[meio + 1 + j];

    size_t i = 0, j = 0, k = esq; // Índices para arrays temporários e o array principal
    while (i < n1 && j < n2) {
        (*numComparacoes)++; 
        if (temp_ESQ[i] <= temp_DIR[j]) {
            vetor[k++] = temp_ESQ[i++];
        } else {
            vetor[k++] = temp_DIR[j++];
        }
    }

    // Copia os elementos restantes de temp_ESQ[], se houver
    while (i < n1) {
        vetor[k++] = temp_ESQ[i++];
    }

    // Copia os elementos restantes de temp_DIR[], se houver
    while (j < n2) {
        vetor[k++] = temp_DIR[j++];
    }
}

// Auxiliar para a ordenação por merge recursiva
void mergeSortAux(int vetor[], int temp_ESQ[], int temp_DIR[], size_t esq, size_t dir, uint64_t* numComparacoes) {
    if (esq < dir) {
        size_t meio = esq + (dir - esq) / 2; // Calcula o ponto médio
        mergeSortAux(vetor, temp_ESQ, temp_DIR, esq, meio, numComparacoes); // Ordena a primeira metade
        mergeSortAux(vetor, temp_ESQ, temp_DIR, meio + 1, dir, numComparacoes); // Ordena a segunda metade
        merge(vetor, temp_ESQ, temp_DIR, esq, meio, dir, numComparacoes); // Intercala as duas metades ordenadas
    }
}

// Ordenação por merge recursiva
uint64_t mergeSortRec(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    int *temp_ESQ = malloc(tam / 2 * sizeof(int)); // Aloca memória para a metade esquerda temporária
    int *temp_DIR = malloc((tam - tam / 2) * sizeof(int)); // Aloca memória para a metade direita temporária
    mergeSortAux(vetor, temp_ESQ, temp_DIR, 0, tam - 1, &numComparacoes); 
    free(temp_ESQ); // Libera a memória alocada para a metade esquerda
    free(temp_DIR); // Libera a memória alocada para a metade direita
    return numComparacoes; 
}
