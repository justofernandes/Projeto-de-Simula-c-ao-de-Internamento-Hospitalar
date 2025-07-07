CC = gcc
CFLAGS = -Wall -Iinclude

OBJETOS = paciente.o fila.o leito.o historico.o main.o

all: simulador

simulador: $(OBJETOS)
	$(CC) $(CFLAGS) -o simulador $(OBJETOS)

paciente.o: src/paciente.c
	$(CC) $(CFLAGS) -c src/paciente.c

fila.o: src/fila.c
	$(CC) $(CFLAGS) -c src/fila.c

leito.o: src/leito.c
	$(CC) $(CFLAGS) -c src/leito.c

historico.o: src/historico.c
	$(CC) $(CFLAGS) -c src/historico.c

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

clean:
	rm -f *.o simulador processamento.log
