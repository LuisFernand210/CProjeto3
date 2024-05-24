#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

void inicializar_agenda(Agenda *agenda) {
    agenda->quantidade_contatos_pessoais = 0;
    agenda->quantidade_contatos_trabalho = 0;
}

int telefone_existe(Contato *contatos, int quantidade, const char *telefone) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(contatos[i].telefone, telefone) == 0) {
            return 1; // Telefone já existe
        }
    }
    return 0; // Telefone não existe
}

void adicionar_contato(Agenda *agenda, int tipo) {
    Contato *contatos;
    int *quantidade_contatos;
    if (tipo == 1) { // Contato pessoal
        contatos = agenda->contatos_pessoais;
        quantidade_contatos = &agenda->quantidade_contatos_pessoais;
    } else { // Contato de trabalho
        contatos = agenda->contatos_trabalho;
        quantidade_contatos = &agenda->quantidade_contatos_trabalho;
    }

    if (*quantidade_contatos >= MAX_CONTATOS) {
        printf("Nao e possivel adicionar mais contatos. Agenda cheia.\n");
        return;
    }

    Contato novo_contato;
    printf("Nome: ");
    scanf("%s", novo_contato.nome);
    printf("Sobrenome: ");
    scanf("%s", novo_contato.sobrenome);
    printf("Email: ");
    scanf("%s", novo_contato.email);
    printf("Telefone: ");
    scanf("%s", novo_contato.telefone);

    if (telefone_existe(contatos, *quantidade_contatos, novo_contato.telefone)) {
        printf("Erro: Telefone ja existe.\n");
        return;
    }

    contatos[*quantidade_contatos] = novo_contato;
    (*quantidade_contatos)++;
}

void listar_contatos(Agenda *agenda, int tipo) {
    Contato *contatos;
    int quantidade_contatos;
    if (tipo == 1) { // Contatos pessoais
        contatos = agenda->contatos_pessoais;
        quantidade_contatos = agenda->quantidade_contatos_pessoais;
    } else { // Contatos de trabalho
        contatos = agenda->contatos_trabalho;
        quantidade_contatos = agenda->quantidade_contatos_trabalho;
    }

    printf("\n===== Contatos =====\n");
    for (int i = 0; i < quantidade_contatos; i++) {
        Contato contato = contatos[i];
        printf("%d. %s %s, %s, %s\n", i + 1, contato.nome, contato.sobrenome, contato.email, contato.telefone);
    }
}

void deletar_contato(Agenda *agenda, int tipo) {
    Contato *contatos;
    int *quantidade_contatos;
    if (tipo == 1) { // Contato pessoal
        contatos = agenda->contatos_pessoais;
        quantidade_contatos = &agenda->quantidade_contatos_pessoais;
    } else { // Contato de trabalho
        contatos = agenda->contatos_trabalho;
        quantidade_contatos = &agenda->quantidade_contatos_trabalho;
    }

    char telefone_deletar[MAX_TELEFONE];
    printf("Digite o telefone do contato que deseja deletar: ");
    scanf("%s", telefone_deletar);

    for (int i = 0; i < *quantidade_contatos; i++) {
        if (strcmp(contatos[i].telefone, telefone_deletar) == 0) {
            for (int j = i; j < *quantidade_contatos - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            (*quantidade_contatos)--;
            printf("Contato deletado com sucesso.\n");
            return;
        }
    }

    printf("Contato com telefone %s nao encontrado.\n", telefone_deletar);
}

void salvar_agenda(Agenda *agenda) {
    FILE *arquivo = fopen("agenda.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(agenda, sizeof(Agenda), 1, arquivo);

    fclose(arquivo);
}

void carregar_agenda(Agenda *agenda) {
    FILE *arquivo = fopen("agenda.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de agenda nao encontrado.\n");
        return;
    }

    fread(agenda, sizeof(Agenda), 1, arquivo);

    fclose(arquivo);
}

void alterar_contato(Agenda *agenda, int tipo) {
    Contato *contatos;
    int quantidade_contatos;
    if (tipo == 1) { // Contato pessoal
        contatos = agenda->contatos_pessoais;
        quantidade_contatos = agenda->quantidade_contatos_pessoais;
    } else { // Contato de trabalho
        contatos = agenda->contatos_trabalho;
        quantidade_contatos = agenda->quantidade_contatos_trabalho;
    }

    char email_busca[MAX_EMAIL];
    printf("Digite o email do contato que deseja alterar: ");
    scanf("%s", email_busca);

    for (int i = 0; i < quantidade_contatos; i++) {
        if (strcmp(contatos[i].email, email_busca) == 0) {
            int opcao;
            do {
                printf("\n===== Alterar Contato =====\n");
                printf("1. Mudar nome\n");
                printf("2. Mudar sobrenome\n");
                printf("3. Mudar email\n");
                printf("4. Mudar telefone\n");
                printf("0. Voltar\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        printf("Novo nome: ");
                        scanf("%s", contatos[i].nome);
                        break;
                    case 2:
                        printf("Novo sobrenome: ");
                        scanf("%s", contatos[i].sobrenome);
                        break;
                    case 3:
                        printf("Novo email: ");
                        scanf("%s", contatos[i].email);
                        break;
                    case 4:
                        {
                            char novo_telefone[MAX_TELEFONE];
                            printf("Novo telefone: ");
                            scanf("%s", novo_telefone);
                            if (telefone_existe(contatos, quantidade_contatos, novo_telefone)) {
                                printf("Erro: Telefone ja existe.\n");
                            } else {
                                strcpy(contatos[i].telefone, novo_telefone);
                            }
                        }
                        break;
                    case 0:
                        printf("Voltando ao menu principal...\n");
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
            } while (opcao != 0);
            return;
        }
    }

    printf("Contato com email %s nao encontrado.\n", email_busca);
}
