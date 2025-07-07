#ifndef FILA_H
#define FILA_H

#include "paciente.h"

#define TAM_DEQUE 20

typedef struct NodoFila { //Nó da fila dupla(deque). Cada nó representa um paciente na fila de espera
    Paciente paciente;
    struct NodoFila *prox, *ant;
} NodoFila;

typedef struct {    // estrutura principal do deque. Mantém o controle da fila de pacientes  
    NodoFila *inicio;
    NodoFila *fim;
    int tamanho;
} Deque;

//Definicoes dos metodos e funcoes 
void inicializar_fila(Deque *fila);
int inserir_fila(Deque *fila, Paciente p);
Paciente remover_fila(Deque *fila);
int fila_vazia(Deque *fila);

#endif
