#include <stdio.h>
#include <stdlib.h>
#include "../include/fila.h"

void inicializar_fila(Deque *fila) {
    fila->inicio = fila->fim = NULL;
    fila->tamanho = 0;
}

int inserir_fila(Deque *fila, Paciente p) {
    if (fila->tamanho >= TAM_DEQUE)
        return 0;

    NodoFila *novo = malloc(sizeof(NodoFila));
    novo->paciente = p;
    novo->prox = novo->ant = NULL;

    if (p.prioridade >= 4) {
        novo->prox = fila->inicio;
        if (fila->inicio) fila->inicio->ant = novo;
        fila->inicio = novo;
        if (!fila->fim) fila->fim = novo;
    } else {
        novo->ant = fila->fim;
        if (fila->fim) fila->fim->prox = novo;
        fila->fim = novo;
        if (!fila->inicio) fila->inicio = novo;
    }

    fila->tamanho++;
    return 1;
}

Paciente remover_fila(Deque *fila) {
    NodoFila *remover;
    Paciente paciente;

    if (!fila->inicio) {
        printf("Erro: Fila vazia.\n");
        exit(1);
    }

    NodoFila *ini = fila->inicio;
    NodoFila *fim = fila->fim;

    if (ini->paciente.prioridade >= fim->paciente.prioridade) {
        remover = ini;
        fila->inicio = ini->prox;
        if (fila->inicio) fila->inicio->ant = NULL;
        if (fila->fim == remover) fila->fim = NULL;
    } else {
        remover = fim;
        fila->fim = fim->ant;
        if (fila->fim) fila->fim->prox = NULL;
        if (fila->inicio == remover) fila->inicio = NULL;
    }

    paciente = remover->paciente;
    free(remover);
    fila->tamanho--;
    return paciente;
}

int fila_vazia(Deque *fila) {
    return fila->tamanho == 0;
}
