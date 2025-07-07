#ifndef HISTORICO_H
#define HISTORICO_H

#include "paciente.h"

typedef struct NoHist { //Representa um nó da pilha de histórico.
    Paciente paciente; 
    struct NoHist *prox;
} NoHist;

typedef struct { //Estrutura da pilha que controla os pacientes já atendidos.
    NoHist *topo;
} PilhaHistorico;

void inicializar_pilha(PilhaHistorico *p);
void empilhar_historico(PilhaHistorico *p, Paciente p_data);

#endif
