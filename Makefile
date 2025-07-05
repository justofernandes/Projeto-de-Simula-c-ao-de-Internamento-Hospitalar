CC = gcc
CFLAGS = -Wall
INCLUDES = -Iinclude
SRC = src/paciente.c src/fila.c src/leito.c src/historico.c src/main.c

ifeq ($(OS),Windows_NT)
	EXE = .exe
else
	EXE =
endif

OUT = simulador$(EXE)

all: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(INCLUDES)

clean:
ifeq ($(OS),Windows_NT)
	del /Q $(OUT) processamento.log 2>nul
else
	rm -f $(OUT) processamento.log
endif
