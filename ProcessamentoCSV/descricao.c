#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "descricao.h"
#include "io.h"

double calcularMedia(double *valores, int tamanho) {
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += valores[i];
    }
    return soma / tamanho;
}

double calcularMediana(double *valores, int tamanho) {
    if (tamanho % 2 == 0) {
        return (valores[tamanho / 2 - 1] + valores[tamanho / 2]) / 2.0;
    } else {
        return valores[tamanho / 2];
    }
}

void calcularEImprimirModa(double *valores, int tamanho) {
    int maxFreq = 0;
    double moda = valores[0];
    int freqAtual = 1;
    for (int i = 1; i < tamanho; i++) {
        if (valores[i] == valores[i - 1]) {
            freqAtual++;
        } else {
            if (freqAtual > maxFreq) {
                maxFreq = freqAtual;
                moda = valores[i - 1];
            }
            freqAtual = 1;
        }
    }
    // Verificar a última sequência de valores
    if (freqAtual > maxFreq) {
        moda = valores[tamanho - 1];
        maxFreq = freqAtual;
    }
    printf("Moda: %.2f (%d vezes)\n", moda, maxFreq);
}

double calcularDesvioPadrao(double *valores, int tamanho, double media) {
    double somaQuadrados = 0.0;
    for (int i = 0; i < tamanho; i++) {
        somaQuadrados += pow(valores[i] - media, 2);
    }
    return sqrt(somaQuadrados / tamanho);
}

double encontrarMinimo(double *valores, int tamanho) {
    double min = valores[0];
    for (int i = 1; i < tamanho; i++) {
        if (valores[i] < min) min = valores[i];
    }
    return min;
}

double encontrarMaximo(double *valores, int tamanho) {
    double max = valores[0];
    for (int i = 1; i < tamanho; i++) {
        if (valores[i] > max) max = valores[i];
    }
    return max;
}

void imprimirValoresUnicos(double *valores, int tamanho) {
    printf("Valores unicos: [");
    for (int i = 0; i < tamanho; i++) {
        if (i == 0 || valores[i] != valores[i - 1]) {
            printf("%.2f", valores[i]);
            if (i < tamanho - 1 && valores[i] != valores[i + 1]) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}
// Supondo que a função para encontrar o índice da coluna esteja implementada
int encontrarIndiceDaColuna(DadosCSV *csv, const char *nomeColuna) {
    for (int i = 0; i < csv->num_colunas; i++) {
        if (strcmp(csv->cabecalhos[i], nomeColuna) == 0) {
            return i;
        }
    }
    return -1;
}

int comparar(const void *a, const void *b) {
    double diferenca = *(double*)a - *(double*)b;
    return (diferenca > 0) - (diferenca < 0);
}

void descreverVariavelNumerica(DadosCSV *csv, const char *nomeColuna) {
    int indice = encontrarIndiceDaColuna(csv, nomeColuna);
    if (indice == -1) {
        printf("Coluna não encontrada.\n");
        return;
    }

    // Extrair valores numéricos para um array
    double *valores = malloc(csv->num_linhas * sizeof(double));
    int valoresValidos = 0;
    for (int i = 0; i < csv->num_linhas; i++) {
        if (strcmp(csv->dados[i][indice], "NaN") != 0) {
            valores[valoresValidos++] = atof(csv->dados[i][indice]);
        }
    }

    if (valoresValidos > 0) {
        // Ordenar valores
        qsort(valores, valoresValidos, sizeof(double), comparar);

        // Calcular e imprimir estatísticas
        printf("Contador: %d\n", valoresValidos);
        printf("Média: %.2f\n", calcularMedia(valores, valoresValidos));
        printf("Mediana: %.2f\n", calcularMediana(valores, valoresValidos));
        calcularEImprimirModa(valores, valoresValidos); // Implementar essa função baseada na descrição anterior
        printf("Desvio: %.2f\n", calcularDesvioPadrao(valores, valoresValidos, calcularMedia(valores, valoresValidos)));
        printf("Min.: %.2f\n", encontrarMinimo(valores, valoresValidos));
        printf("Max.: %.2f\n", encontrarMaximo(valores, valoresValidos));
        imprimirValoresUnicos(valores, valoresValidos); // Implementar essa função baseada na descrição anterior
    } else {
        printf("Nenhum dado numérico válido encontrado.\n");
    }

    free(valores); // Liberar a memória alocada para os valores
}

void descreverVariavelCategorica(DadosCSV *csv, const char *nomeColuna) {
    int indice = encontrarIndiceDaColuna(csv, nomeColuna);
    if (indice == -1) {
        printf("Coluna não encontrada.\n");
        return;
    }

    // Array dinâmico para armazenar frequências dos valores únicos
    FrequenciaValor *frequencias = malloc(csv->num_linhas * sizeof(FrequenciaValor));
    int numValoresUnicos = 0;
    
    for (int i = 0; i < csv->num_linhas; i++) {
        char *valorAtual = csv->dados[i][indice];
        int encontrado = 0;
        for (int j = 0; j < numValoresUnicos; j++) {
            if (strcmp(frequencias[j].valor, valorAtual) == 0) {
                frequencias[j].frequencia++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            frequencias[numValoresUnicos].valor = valorAtual;
            frequencias[numValoresUnicos].frequencia = 1;
            numValoresUnicos++;
        }
    }

    // Encontrar a moda
    int maxFrequencia = 0;
    char *moda = NULL;
    for (int i = 0; i < numValoresUnicos; i++) {
        if (frequencias[i].frequencia > maxFrequencia) {
            moda = frequencias[i].valor;
            maxFrequencia = frequencias[i].frequencia;
        }
    }

    // Imprimir resultados
    printf("Contador: %d\n", csv->num_linhas);
    printf("Moda: %s (%d vezes)\n", moda, maxFrequencia);
    printf("Valores unicos: [");
    for (int i = 0; i < numValoresUnicos; i++) {
        printf("%s", frequencias[i].valor);
        if (i < numValoresUnicos - 1) printf(", ");
    }
    printf("]\n");

    free(frequencias); // Não esqueça de liberar a memória alocada
}


