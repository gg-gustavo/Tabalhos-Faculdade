# Avaliador de Expressões em Notação Prefixada (Polonesa)

Este projeto implementa um avaliador de expressões matemáticas em **notação prefixada** (ou **notação polonesa**), usando linguagem C. A notação prefixada é uma maneira de escrever expressões matemáticas em que o operador é colocado antes dos operandos. Este formato elimina a necessidade de parênteses e permite a avaliação de expressões de forma recursiva e eficiente.

## Sumário

- [Introdução](#introdução)
- [Como Funciona](#como-funciona)
- [Como Usar](#como-usar)
- [Exemplos](#exemplos)
- [Compilação e Execução](#compilação-e-execução)

---

## Introdução

O avaliador de expressões em notação prefixada lê a entrada fornecida e executa operações matemáticas básicas, incluindo:

- Adição (`+`)
- Subtração (`-`)
- Multiplicação (`*`)
- Divisão (`/`)
- Exponenciação (`^`)
- Logaritmo (`log`), que permite calcular logaritmos em uma base específica.

## Como Funciona

### Notação Prefixada (Polonesa)

Na **notação prefixada**, o operador é escrito antes dos operandos. Por exemplo, uma expressão comum como `3 + 5` seria escrita em notação prefixada como `+ 3 5`. Este formato é útil em cálculos computacionais e elimina a necessidade de parênteses, pois a ordem das operações é determinada pela posição dos operadores.

A função `avalia` implementa a avaliação recursiva da expressão em notação prefixada. Ela:

1. Lê um item da entrada.
2. Determina se o item é um operador ou um número:
   - Se for um número, converte-o para `double` e retorna o valor.
   - Se for um operador, chama-se recursivamente para avaliar os operandos subsequentes.
3. Realiza a operação associada ao operador e retorna o resultado.

### Operador de Logaritmo

O operador `log` permite calcular logaritmos em uma base específica. A sintaxe para o logaritmo é:

Por exemplo, `log 100 10` calcula o logaritmo de 100 na base 10.

## Como Usar

### Entrada

As expressões são lidas da entrada padrão (stdin) e devem estar em formato de **notação prefixada**. Cada item (operador ou operando) deve ser separado por espaço.

### Operadores Suportados

| Operador | Operação              | Exemplo          |
|----------|------------------------|------------------|
| `+`      | Adição                | `+ 3 5`         |
| `-`      | Subtração             | `- 10 2`        |
| `*`      | Multiplicação         | `* 4 3`         |
| `/`      | Divisão               | `/ 8 2`         |
| `^`      | Exponenciação         | `^ 2 3`         |
| `log`    | Logaritmo (base N)    | `log 100 10`    |

### Saída

O resultado da expressão é impresso no console como um valor de ponto flutuante (`double`).

## Exemplos

1. **Adição**
   ```plaintext
   Entrada: + 10 5
   Saída: 15
### Expressão Complexa

- **Entrada:** `+ * 3 4 - 10 2`
- **Saída:** `14`

Esta expressão calcula: `(3 * 4) + (10 - 2)`

---

### Logaritmo em Base 10

- **Entrada:** `log 100 10`
- **Saída:** `2`

---

### Exponenciação

- **Entrada:** `^ 2 3`
- **Saída:** `8`

---

## Compilação e Execução

O projeto possui a seguinte estrutura: 

.  
    └── src 
    ├── avalia.c 
    ├── avalia.h 
    ├── makefile 
    ├── testa 
    └── testa.c

Para compilar e executar o código, siga as etapas abaixo:

1. **Compile o código com o Makefile:**
    ```bash
    make
2. **Execute o programa:**
    ```bash
    ./testa
3. **Insira a expressão em notação prefixada** e pressione **Enter** para ver o resultado.