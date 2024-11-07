#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "avalia.h"

// Função que lê o próximo item da expressão
char *proximo_item(void) {
    static char buffer[TAMANHO_MAXIMO_ITEM + 1];
    // Lê um item da entrada e armazena no buffer
    if (scanf("%s", buffer) == EOF) return NULL;
    // Aloca memória para o item e copia o conteúdo do buffer
    return strcpy(malloc(sizeof(char) * (strlen(buffer) + 1)), buffer);
}

// Função recursiva para avaliar a expressão em notação prefixa
double avalia(void) {
    // Obtém o próximo item da expressão
    char *item = proximo_item();

    // Caso base: se não houver item, retornar NAN (valor indefinido)
    if (item == NULL) return NAN;

    // Verifica se o item é um número
    if (isdigit(item[0]) || (item[0] == '-' && isdigit(item[1]))) {
        // Converte o item para double
        double value = strtod(item, NULL);
        free(item);  // Libera a memória alocada para o item
        return value;  // Retorna o valor numérico
    }

    // Variável para armazenar o resultado da operação
    double resultado = 0.0;
    
    // Verifica o tipo de operador e realiza a operação correspondente
    if (strcmp(item, "+") == 0) {
        free(item);  // Libera o operador da memória
        double op1 = avalia();  // Avalia o primeiro operando
        double op2 = avalia();  // Avalia o segundo operando
        resultado = op1 + op2;  // Realiza a soma
    } else if (strcmp(item, "-") == 0) {
        free(item);
        double op1 = avalia();
        double op2 = avalia();
        resultado = op1 - op2;  // Realiza a subtração
    } else if (strcmp(item, "*") == 0) {
        free(item);
        double op1 = avalia();
        double op2 = avalia();
        resultado = op1 * op2;  // Realiza a multiplicação
    } else if (strcmp(item, "/") == 0) {
        free(item);
        double op1 = avalia();
        double op2 = avalia();
        resultado = op1 / op2;  // Realiza a divisão
    } else if (strcmp(item, "^") == 0) {
        free(item);
        double base = avalia();      // Avalia a base
        double expoente = avalia();   // Avalia o expoente
        resultado = pow(base, expoente);  // Calcula a potência
    } else if (strcmp(item, "log") == 0) {
        free(item);
        double numero = avalia();     // Avalia o número
        double base = avalia();       // Avalia a base do logaritmo
        resultado = log(numero) / log(base);  // Calcula o logaritmo na base especificada
    } else {
        // Caso o operador não seja conhecido, retornar NAN (valor indefinido)
        free(item);
        resultado = NAN;
    }

    // Retorna o resultado da operação
    return resultado;
}
