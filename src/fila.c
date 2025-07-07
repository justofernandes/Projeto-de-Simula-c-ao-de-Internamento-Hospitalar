#include <stdio.h>
#include <stdlib.h>
#include "../include/fila.h"

//Inicia o deque com inicio e fim = NULL;
void inicializar_fila(Deque *fila) {
    fila->inicio = fila->fim = NULL;
    fila->tamanho = 0;
}

//Responsável por adicionar um novo paciente ao deque
int inserir_fila(Deque *fila, Paciente p) {
    if (fila->tamanho >= TAM_DEQUE) //Verifica se está cheio
        return 0;

    //Aloca memoria para um novo no, ja definindo inicio e fim como null
    NodoFila *novo = malloc(sizeof(NodoFila));
    novo->paciente = p;
    novo->prox = novo->ant = NULL;

    // Adiciona no inicio
    if (p.prioridade >= 4) {
        if (fila->inicio) {
            novo->prox = fila->inicio;
            fila->inicio->ant = novo;
        }
        fila->inicio = novo;

        if (!fila->fim)
            fila->fim = novo;

    } else { // adiciona no fim
        if (fila->fim) {
            novo->ant = fila->fim;
            fila->fim->prox = novo;
        }
        fila->fim = novo;

        if (!fila->inicio)
            fila->inicio = novo;
    }

    fila->tamanho++;    //Adiicona +1 na quantidade
    return 1;
}

//Remove um paciente da fila
Paciente remover_fila(Deque *fila) {
    NodoFila *remover;
    Paciente paciente;

    if (!fila->inicio) {
        printf("Erro: Fila vazia.\n"); //Verifica se a fila está vazia
        exit(1);
    }

    //Ponteiros auxiliares
    NodoFila *ini = fila->inicio;
    NodoFila *fim = fila->fim;

    // Comparação de prioridades inicio e fim do deque
    if (ini->paciente.prioridade >= fim->paciente.prioridade) {
        // Remove do início
        remover = ini;
        fila->inicio = ini->prox;
        if (fila->inicio) {
            fila->inicio->ant = NULL;
        }
        if (fila->fim == remover) {
            fila->fim = NULL;
        }
    } else {
        // Remove do fim
        remover = fim;
        fila->fim = fim->ant;
        if (fila->fim) {
            fila->fim->prox = NULL;
        }
        if (fila->inicio == remover) {
            fila->inicio = NULL;
        }
    }

    paciente = remover->paciente;
    free(remover);
    fila->tamanho--; //Decrementa
    return paciente;
}

int fila_vazia(Deque *fila) {
    return fila->tamanho == 0;
}
