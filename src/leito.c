#include <stdlib.h>
#include "../include/leito.h"

void inicializar_leitos(Leitos *l) {
    for (int i = 0; i < MAX_LEITOS; i++) {
        l->leitos[i] = NULL;
        l->ocupados[i] = 0;
    }
}

int internar_paciente(Leitos *l, Paciente p) {
    for (int i = 0; i < MAX_LEITOS; i++) {
        if (!l->ocupados[i]) {
            l->leitos[i] = malloc(sizeof(Paciente));
            *(l->leitos[i]) = p;
            l->ocupados[i] = 1;
            return i;
        }
    }
    return -1;
}

int liberar_leito(Leitos *l, int indice) {
    if (indice >= 0 && indice < MAX_LEITOS && l->ocupados[indice]) {
        free(l->leitos[indice]);
        l->leitos[indice] = NULL;
        l->ocupados[indice] = 0;
        return 1;
    }
    return 0;
}
