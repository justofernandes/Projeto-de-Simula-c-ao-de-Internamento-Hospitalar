#ifndef FILA_H
#define FILA_H

#include "paciente.h"

#define TAM_DEQUE 20

typedef struct NodoFila {
    Paciente paciente;
    struct NodoFila *prox, *ant;
} NodoFila;

typedef struct {
    NodoFila *inicio;
    NodoFila *fim;
    int tamanho;
} Deque;

void inicializar_fila(Deque *fila);
int inserir_fila(Deque *fila, Paciente p);
Paciente remover_fila(Deque *fila);
int fila_vazia(Deque *fila);

#endif
