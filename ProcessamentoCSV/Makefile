CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm

# Lista de arquivos objeto
OBJS = csvreader.o io.o descricao.o filtro.o selecao.o faltantes.o ordena.o salvar.o

# Executável principal
MAIN = csvreader

# Target padrão
all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Regra padrão para arquivos objeto
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

# Caso especial sem arquivo header
csvreader.o: csvreader.c
	$(CC) $(CFLAGS) -c $<

# Limpar os arquivos de build
clean:
	rm -f *.o *~ $(MAIN)
	find . -name "*.csv" | grep -vE "Teste1.csv|Teste2.csv" | xargs rm -f

# Limpar e compilar
cc:
	make clean
	clear
	make

# Depuração com Valgrind
debug:
	make cc
	clear
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes ./$(MAIN) Teste1.csv
