#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/paciente.h"

#define TAM_LINHA 256

// Tabela hash 
static struct NoPaciente {
    Paciente paciente;
    struct NoPaciente *prox;
} *tabela_hash[TAM_TABELA];

void inicializar_tabela() {
    for (int i = 0; i < TAM_TABELA; i++)
        tabela_hash[i] = NULL;
}

int funcao_hash(const char *id) {
    int soma = 0;
    for (int i = 0; id[i] != '\0'; i++)
        soma += id[i];
    return soma % TAM_TABELA;
}

void inserir_paciente(Paciente p) {
    int indice = funcao_hash(p.id);
    struct NoPaciente *novo = malloc(sizeof(struct NoPaciente));
    if (!novo) {
        perror("Erro ao alocar memória para paciente");
        exit(1);
    }
    novo->paciente = p;
    novo->prox = tabela_hash[indice];
    tabela_hash[indice] = novo;
}

void carregar_pacientes_csv(const char *caminho) {
    FILE *arquivo = fopen(caminho, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de pacientes");
        exit(1);
    }

    char linha[TAM_LINHA];
    int linha_atual = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (linha_atual++ == 0) continue;  // pular cabeçalho

        Paciente p;
        char *token = strtok(linha, ";");
        int campo = 0;

        while (token != NULL) {
            switch (campo) {
                case 0: strncpy(p.id, token, sizeof(p.id)); p.id[sizeof(p.id)-1] = '\0'; break;
                case 1: strncpy(p.nome, token, sizeof(p.nome)); p.nome[sizeof(p.nome)-1] = '\0'; break;
                case 2: p.idade = atoi(token); break;
                case 3: p.sexo = token[0]; break;
                case 4: strncpy(p.cpf, token, sizeof(p.cpf)); p.cpf[sizeof(p.cpf)-1] = '\0'; break;
                case 5: p.prioridade = atoi(token); break;
                case 6: p.atendido = atoi(token); break;
            }
            token = strtok(NULL, ";");
            campo++;
        }

        inserir_paciente(p);
    }

    fclose(arquivo);
}

Paciente* sortear_paciente() {
    srand(time(NULL));
    for (int tentativas = 0; tentativas < 200; tentativas++) {
        int indice = rand() % TAM_TABELA;
        struct NoPaciente *atual = tabela_hash[indice];

        while (atual) {
            if (atual->paciente.atendido == 0) {
                atual->paciente.atendido = 1;
                return &atual->paciente;
            }
            atual = atual->prox;
        }
    }
    return NULL;
}

int paciente_disponivel() {
    for (int i = 0; i < TAM_TABELA; i++) {
        struct NoPaciente *atual = tabela_hash[i];
        while (atual) {
            if (atual->paciente.atendido == 0)
                return 1;
            atual = atual->prox;
        }
    }
    return 0;
}

void registrar_log(const char *mensagem) {
    FILE *log = fopen("processamento.log", "a");
    if (log) {
        fprintf(log, "%s\n", mensagem);
        fclose(log);
    }
    printf("%s\n", mensagem);
}
