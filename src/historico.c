#include <stdlib.h>
#include "../include/historico.h"

void inicializar_pilha(PilhaHistorico *p) {
    p->topo = NULL;
}

void empilhar_historico(PilhaHistorico *p, Paciente p_data) {
    NoHist *novo = malloc(sizeof(NoHist));
    novo->paciente = p_data;
    novo->prox = p->topo;
    p->topo = novo;
}
