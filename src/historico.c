#include <stdlib.h>
#include "../include/historico.h"

void inicializar_pilha(PilhaHistorico *p) { //inicializa a pilha de histórico. Define o topo como NULL.
    p->topo = NULL;
}

void empilhar_historico(PilhaHistorico *p, Paciente p_data) { //Cria um novo nó com os dados do paciente que teve alta:
    NoHist *novo = malloc(sizeof(NoHist));
    novo->paciente = p_data;
    novo->prox = p->topo;
    p->topo = novo;
}
