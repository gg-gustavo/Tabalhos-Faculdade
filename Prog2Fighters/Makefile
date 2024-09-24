CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lallegro -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = prog2_fighter

all: $(TARGET)

$(TARGET): main.o $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJ) main.o $(TARGET)

.PHONY: all clean
