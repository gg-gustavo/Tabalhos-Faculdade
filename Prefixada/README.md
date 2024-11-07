# 🔢 Avaliador de Expressões em Notação Prefixada (Polonesa)

Este projeto implementa um avaliador de expressões matemáticas em **notação prefixada** (ou **notação polonesa**), usando linguagem C. A notação prefixada é uma maneira de escrever expressões matemáticas em que o operador é colocado antes dos operandos. Este formato elimina a necessidade de parênteses e permite a avaliação de expressões de forma recursiva e eficiente.

## 📖 Introdução

O avaliador de expressões em notação prefixada lê a entrada fornecida e executa operações matemáticas básicas, incluindo:

- Adição (`+`)
- Subtração (`-`)
- Multiplicação (`*`)
- Divisão (`/`)
- Exponenciação (`^`)
- Logaritmo (`log`), que permite calcular logaritmos em uma base específica.

## ⚙️ Como Funciona

Na **notação prefixada**, o operador é escrito antes dos operandos. Por exemplo, uma expressão comum como `3 + 5` seria escrita em notação prefixada como `+ 3 5`. Este formato é útil em cálculos computacionais e elimina a necessidade de parênteses, pois a ordem das operações é determinada pela posição dos operadores.

A função `avalia` implementa a avaliação recursiva da expressão em notação prefixada. Ela:

1. Lê um item da entrada.
2. Determina se o item é um operador ou um número:
   - Se for um número, converte-o para `double` e retorna o valor.
   - Se for um operador, chama-se recursivamente para avaliar os operandos subsequentes.
3. Realiza a operação associada ao operador e retorna o resultado.

### Operador de Logaritmo

O operador `log` permite calcular logaritmos em uma base específica. A sintaxe para o logaritmo é `log <numero> <base>`. Por exemplo, `log 100 10` calcula o logaritmo de 100 na base 10.

## 📋 Funcionalidades

O avaliador suporta as seguintes operações matemáticas em notação prefixada:

| Operador | Operação              | Exemplo          |
|----------|------------------------|------------------|
| `+`      | Adição                | `+ 3 5`         |
| `-`      | Subtração             | `- 10 2`        |
| `*`      | Multiplicação         | `* 4 3`         |
| `/`      | Divisão               | `/ 8 2`         |
| `^`      | Exponenciação         | `^ 2 3`         |
| `log`    | Logaritmo (base N)    | `log 100 10`    |

## 📂 Estrutura do Projeto

Abaixo está a estrutura dos arquivos do projeto:
```bash
. 
└── src 
|   ├── avalia.c # Implementação da função de avaliação 
|   ├── avalia.h # Header file da função de avaliação 
|   ├── makefile # Automação da compilação 
|   ├── testa # Executável gerado após compilação 
|   └── testa.c # Função principal (main) para executar a avaliação
├── README.md # Documentação do projeto 
```

## 🚀 Como Executar

### Pré-requisitos

- Compilador C (GCC ou equivalente) para compilar o projeto.

### Instruções para Compilar e Executar

1. Navegue até o diretório `src`:

   ```bash
   cd src
2. Compile o projeto usando o `makefile`:

   ```bash
   make
Esse comando irá compilar os arquivos `avalia.c` e `testa.c`, gerando o executável `testa`.

3. Para limpar arquivos de objeto (*.o) e outros arquivos temporários, use:

   ```bash
   make clean
4. Execute o programa:
   ```bash
   ./testa
5. Insira uma expressão em notação prefixada e pressione Enter para ver o resultado. Por exemplo:
   ```bash
   Entrada: + * 3 4 - 10 2
   Saída: 14
## 📚 O que Eu Aprendi

Neste projeto, aprendi a:

**-Implementar e entender a notação prefixada (Polonesa):** Compreendi como a notação prefixada organiza operações e operandos, eliminando a necessidade de parênteses, o que facilita a implementação de um avaliador recursivo.

**-Usar recursão para avaliação de expressões:** Utilizei uma função recursiva para avaliar expressões matemáticas prefixadas, permitindo que cada operação dependa dos valores calculados nas chamadas recursivas anteriores.

## 🛠️ Tecnologias Utilizadas

- **Linguagem de Programação**: C
- **IDE**: Visual Studio Code
- **Compilador**: GCC
- **Makefile**: Para automatizar a compilação do projeto