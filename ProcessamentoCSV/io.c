#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Verifica se a string pode ser convertida para um número, retornando 'N' se sim, e 'S' se não.
char converteNumero(char *str) {
    return (atof(str) != 0.0 || strcmp(str, "0") == 0) ? 'N' : 'S';
}

// Libera toda a memória alocada para a estrutura DadosCSV.
void liberarDadosCSV(DadosCSV *csv) {
    if (!csv)
        return;

    // Liberação das strings de dados e dos arrays de ponteiros associados.
    for (int i = 0; i < csv->num_linhas; i++) {
        for (int j = 0; j < csv->num_colunas; j++) {
            free(csv->dados[i][j]);
        }
        free(csv->dados[i]);
    }
    free(csv->dados);

    // Liberação dos cabeçalhos e do array de tipos de coluna.
    for (int i = 0; i < csv->num_colunas; i++) {
        free(csv->cabecalhos[i]);
    }
    free(csv->cabecalhos);
    free(csv->tipo_coluna);
    free(csv);
}

// Função auxiliar para separar campos de uma string baseada em vírgulas.
char* separa(char **string) {
    char *resultado = *string;
    char *pos_virgula = strchr(*string, ',');
    if (pos_virgula) {
        *pos_virgula = '\0';  // Encerra a string atual no ponto da vírgula.
        *string = pos_virgula + 1;
    } else {
        *string = NULL;  // Não há mais campos a serem processados.
    }
    return resultado;
}

// Lê um arquivo CSV e armazena seus dados na estrutura DadosCSV.
DadosCSV *lerCSV(const char *nome_arquivo){
    // Manipulação de erro ao tentar abrir o arquivo.
    FILE *ptr_arquivo = fopen(nome_arquivo, "r");
    if (!ptr_arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", nome_arquivo);
        return NULL;
    }

    // Alocação inicial e tratamento de erros.
    DadosCSV *csv = malloc(sizeof(DadosCSV));
    if (!csv) {
        fprintf(stderr, "Erro ao alocar memória\n");
        fclose(ptr_arquivo);
        return NULL;
    }

    // Processo de leitura e determinação do número de colunas baseado no cabeçalho.
    char linha[MAX_CHARACTERS];
    fgets(linha, MAX_CHARACTERS, ptr_arquivo); // Leitura do cabeçalho.
    csv->num_colunas = 0;
    char *token = strtok(linha, ",");
    while (token) {
        csv->num_colunas++;
        token = strtok(NULL, ",");
    }

    // Realocação conforme a quantidade de colunas detectadas.
    csv->cabecalhos = malloc(csv->num_colunas * sizeof(char *));
    csv->tipo_coluna = malloc(csv->num_colunas * sizeof(char));
    rewind(ptr_arquivo);
    fgets(linha, MAX_CHARACTERS, ptr_arquivo); // Releitura do cabeçalho para armazenar.
    int col = 0;
    token = strtok(linha, ",");
    while (token) {
        csv->cabecalhos[col] = strdup(token);
        token = strtok(NULL, ",");
        col++;
    }

    // Detecção dos tipos de dados a partir da primeira linha de dados.
    if (fgets(linha, MAX_CHARACTERS, ptr_arquivo)) {
        char *dataLine = linha;
        for (int i = 0; i < csv->num_colunas; i++) {
            char *field = separa(&dataLine);
            csv->tipo_coluna[i] = converteNumero(field);
        }
    } else {
        for (int i = 0; i < csv->num_colunas; i++) {
            csv->tipo_coluna[i] = 'S'; // Assumindo string se não há dados.
        }
    }

    // Resetar leitura para começar a capturar os dados efetivamente.
    rewind(ptr_arquivo);
    fgets(linha, MAX_CHARACTERS, ptr_arquivo); // Ignorando cabeçalho.
    csv->num_linhas = 0;
    while (fgets(linha, MAX_CHARACTERS, ptr_arquivo)) {
        csv->num_linhas++;
    }
    csv->dados = malloc(csv->num_linhas * sizeof(char **));
    for (int i = 0; i < csv->num_linhas; i++) {
        csv->dados[i] = malloc(csv->num_colunas * sizeof(char *));
    }

    rewind(ptr_arquivo);
    fgets(linha, MAX_CHARACTERS, ptr_arquivo); // Última leitura do cabeçalho.
    int linhaAtual = 0;
    while (fgets(linha, MAX_CHARACTERS, ptr_arquivo)) {
        char *tempLinha = linha, *campo;
        for (int i = 0; i < csv->num_colunas; i++) {
            campo = separa(&tempLinha);
            if (!campo || strlen(campo) == 0) {
                csv->dados[linhaAtual][i] = strdup("NaN");
            } else {
                csv->dados[linhaAtual][i] = strdup(campo);
            }
        }
        linhaAtual++;
    }

    fclose(ptr_arquivo);
    return csv;
}

// Função para exibir um resumo dos dados CSV com cabeçalhos e tipos de dados.
void mostrarResumo(DadosCSV *csv) {
    if (!csv)
        return;

    printf("\nSumário do Arquivo:\n\n");

    // Exibir cabeçalhos e tipos de coluna formatados
    for (int i = 0; i < csv->num_colunas; i++) {
        printf("%-12s [%c]\n", csv->cabecalhos[i], csv->tipo_coluna[i]);
    }

    // Exibir contagem de variáveis
    printf("%d variáveis encontradas\n", csv->num_colunas);

    // Aguardar pressionar ENTER
    printf("Pressione ENTER para continuar\n");
    getchar(); // Aguarda pressionar ENTER
}

// Função para imprimir as linhas formatadas com larguras de coluna ajustadas.
void imprimirLinhas(DadosCSV *csv, int inicio, int fim, int *comprimentos_maximos) {
    for (int j = inicio; j < fim; j++) {
        printf("%*d", comprimentos_maximos[0], j);
        for (int i = 0; i < csv->num_colunas; i++) {
            printf(" %*s", comprimentos_maximos[i + 1], csv->dados[j][i]);
        }
    }
}

// Função para exibir os dados formatados, mostrando cabeçalhos e linhas selecionadas.
void mostrarDadosFormatados(DadosCSV *csv) {
    if (!csv || csv->num_linhas == 0)
        return;

    int comprimentos_maximos[csv->num_colunas + 1]; // Inclui uma coluna para o número da linha.
    comprimentos_maximos[0] = snprintf(NULL, 0, "%d", csv->num_linhas - 1);
    for (int i = 1; i <= csv->num_colunas; i++) {
        comprimentos_maximos[i] = strlen(csv->cabecalhos[i-1]);
        for (int j = 0; j < csv->num_linhas; j++) {
            int comprimento = strlen(csv->dados[j][i-1]);
            if (comprimento > comprimentos_maximos[i]) {
                comprimentos_maximos[i] = comprimento;
            }
        }
    }

    printf("%*s", comprimentos_maximos[0], ""); // Espaço para a coluna do número da linha.
    for (int i = 0; i < csv->num_colunas; i++) {
        printf(" %*s", comprimentos_maximos[i + 1], csv->cabecalhos[i]);
    }

    int inicio = 0, fim = csv->num_linhas;
    if (csv->num_linhas > 10) {
        fim = 5; // Limita a impressão às primeiras 5 linhas se houver muitas.
        imprimirLinhas(csv, inicio, fim, comprimentos_maximos);
        //printf("...\n");

        inicio = csv->num_linhas - 5; // E às últimas 5 linhas.
    }
    printf(" ");
    // Espaços para alinhamento das linhas de dados com os cabeçalhos ******
    for (int i = 1; i < csv->num_colunas; i++) {
    int spaces_to_add = comprimentos_maximos[i] - strlen(csv->cabecalhos[i - 1]);
    for (int k = 0; k < spaces_to_add; k++) {
        printf(" ");
    }
    printf("  "); // Adicionar espaços adicionais entre as colunas
}
printf("\n");


    imprimirLinhas(csv, inicio, csv->num_linhas, comprimentos_maximos);

    printf("\n[%d rows x %d columns]\n", csv->num_linhas, csv->num_colunas);
    printf("Press ENTER to continue\n");
    getchar();
}