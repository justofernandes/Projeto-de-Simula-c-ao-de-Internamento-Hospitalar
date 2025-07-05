#ifndef HISTORICO_H
#define HISTORICO_H

#include "paciente.h"

typedef struct NoHist {
    Paciente paciente;
    struct NoHist *prox;
} NoHist;

typedef struct {
    NoHist *topo;
} PilhaHistorico;

void inicializar_pilha(PilhaHistorico *p);
void empilhar_historico(PilhaHistorico *p, Paciente p_data);

#endif
