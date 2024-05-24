#ifndef AGENDA_H
#define AGENDA_H

#define MAX_CONTATOS 255
#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_TELEFONE 20

typedef struct {
    char nome[MAX_NOME];
    char sobrenome[MAX_NOME];
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
} Contato;

typedef struct {
    Contato contatos_pessoais[MAX_CONTATOS];
    int quantidade_contatos_pessoais;
    Contato contatos_trabalho[MAX_CONTATOS];
    int quantidade_contatos_trabalho;
} Agenda;

void inicializar_agenda(Agenda *agenda);
void adicionar_contato(Agenda *agenda, int tipo);
void listar_contatos(Agenda *agenda, int tipo);
void deletar_contato(Agenda *agenda, int tipo);
void salvar_agenda(Agenda *agenda);
void carregar_agenda(Agenda *agenda);
int telefone_existe(Contato *contatos, int quantidade, const char *telefone);
void alterar_contato(Agenda *agenda, int tipo);

#endif
