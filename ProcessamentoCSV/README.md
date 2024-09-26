# 📊 Processador de Arquivos CSV

Este projeto foi desenvolvido para a disciplina de Programação 2 com o objetivo de implementar um leitor e processador de arquivos CSV. O programa permite a leitura, análise e manipulação de dados tabulares simples contidos em arquivos CSV. Além disso, oferece funcionalidades como filtros, ordenação e tratamento de dados faltantes.

## 📖 Introdução

Os arquivos CSV são amplamente utilizados para armazenar dados tabulares, porém, o tratamento desses arquivos requer a implementação de algoritmos que permitam uma manipulação eficiente e correta dos dados. Este projeto tem como objetivo construir um processador que seja capaz de ler, analisar e operar sobre arquivos CSV, possibilitando operações como filtragem, ordenação, geração de estatísticas descritivas e tratamento de dados ausentes.

## 📋 Funcionalidades

O programa possui um menu com as seguintes funcionalidades:

1. **Sumário do Arquivo**: Exibe o número de variáveis e suas classificações (String ou Numérica), além da quantidade de registros no arquivo.
2. **Mostrar Dados**: Exibe os 5 primeiros e 5 últimos registros do arquivo.
3. **Filtros**: Filtra os dados com base em variáveis e operadores como `==`, `>=`, `<=`, etc.
4. **Descrição dos Dados**: Exibe estatísticas descritivas de uma variável, como média, mediana, moda e desvio padrão (para variáveis numéricas).
5. **Ordenação**: Ordena os dados com base em uma variável especificada.
6. **Seleção de Variáveis**: Permite ao usuário selecionar colunas específicas do arquivo para exibição e manipulação.
7. **Dados Faltantes**: Detecta, trata e remove registros com valores faltantes (`NaN`).
8. **Salvar Dados**: Permite salvar o arquivo CSV processado com as alterações realizadas.

## 🛠️ Estrutura do Projeto

Abaixo está a estrutura dos arquivos no projeto:
```bash
.
├── csvreader.c      # Função main e controle do menu principal
├── descricao.c      # Estatísticas descritivas
├── descricao.h
├── faltantes.c      # Tratamento de dados faltantes
├── faltantes.h
├── filtro.c         # Implementação de filtros
├── filtro.h
├── io.c             # Entrada/saída de dados
├── io.h
├── Makefile         # Automação da compilação
├── ordena.c         # Ordenação dos dados
├── ordena.h
├── salvar.c         # Salvar dados processados
├── salvar.h
├── selecao.c        # Seleção de variáveis específicas
└── selecao.h
```
## 🚀 Como Executar

### Pré-requisitos

- Compilador C (GCC ou equivalente) para compilar o projeto.
- Python (opcional) para rodar testes e benchmarks automatizados.

### Instruções para Compilar e Executar

1. Clone este repositório:

   ```bash
   git clone https://github.com/gg-gustavo/Trabalhos_Faculdade
2. Acesse o diretório do projeto:

   ```bash
   cd ProcessamentoCSV
3. Compile o projeto usando o Makefile:

   ```bash
    make
4. Execute o programa:

   ```bash
    ./csvreader <arquivo.csv>
## 📚 O que Eu Aprendi

Neste projeto, aprendi a:

- Implementar algoritmos de leitura e manipulação de arquivos CSV de forma eficiente.
- Tratar dados faltantes e realizar operações de filtragem e ordenação sobre grandes volumes de dados.
- Automação de testes e análise de desempenho utilizando scripts e ferramentas adequadas.

## 🛠️ Tecnologias Utilizadas

- **Linguagem de Programação**: C
- **IDE**: Visual Studio Code
- **Compilador**: GCC
- **Makefile**: Para automatizar a compilação do projeto

## ✉️ Contato

Caso tenha dúvidas ou queira mais informações sobre o projeto, sinta-se à vontade para me contatar:

- **Email**: [ggr20@inf.ufpr.br]
- **GitHub**: [github.com/gg-gustavo]

