#ifndef LEITO_H
#define LEITO_H

#include "paciente.h"

#define MAX_LEITOS 10

typedef struct {
    Paciente *leitos[MAX_LEITOS];   //Estrutura para os leitos
    int ocupados[MAX_LEITOS];
} Leitos;

//Definicoes dos metodos e funcoes 
void inicializar_leitos(Leitos *l);
int internar_paciente(Leitos *l, Paciente p);
int liberar_leito(Leitos *l, int indice);

#endif
