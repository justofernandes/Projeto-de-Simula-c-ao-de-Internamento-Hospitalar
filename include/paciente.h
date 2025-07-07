#ifndef PACIENTE_H
#define PACIENTE_H

#define TAM_TABELA 50

//Struct do paciente
typedef struct {
    char id[10];
    char nome[100];
    int idade;
    char sexo;
    char cpf[15];
    int prioridade;
    int atendido;
} Paciente;


//Definicoes dos metodos e funcoes 
void inicializar_tabela();
void carregar_pacientes_csv(const char *caminho);
Paciente* sortear_paciente();
int paciente_disponivel();
void registrar_log(const char *mensagem);

#endif
