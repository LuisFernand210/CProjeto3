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
    Contato contatos[MAX_CONTATOS];
    int quantidade_contatos;
} Agenda;

void inicializar_agenda(Agenda *agenda);
void adicionar_contato(Agenda *agenda);
void listar_contatos(Agenda *agenda);
void deletar_contato(Agenda *agenda);
void salvar_agenda(Agenda *agenda);
void carregar_agenda(Agenda *agenda);

#endif 