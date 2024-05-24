#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

void inicializar_agenda(Agenda *agenda) {
    agenda->quantidade_contatos = 0;
}

int telefone_existe(Agenda *agenda, const char *telefone) {
    for (int i = 0; i < agenda->quantidade_contatos; i++) {
        if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {
            return 1; // Telefone já existe
        }
    }
    return 0; // Telefone não existe
}

void adicionar_contato(Agenda *agenda) {
    if (agenda->quantidade_contatos >= MAX_CONTATOS) {
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

    if (telefone_existe(agenda, novo_contato.telefone)) {
        printf("Erro: Telefone ja existe.\n");
        return;
    }

    agenda->contatos[agenda->quantidade_contatos] = novo_contato;
    agenda->quantidade_contatos++;
}

void listar_contatos(Agenda *agenda) {
    printf("\n===== Contatos =====\n");
    for (int i = 0; i < agenda->quantidade_contatos; i++) {
        Contato contato = agenda->contatos[i];
        printf("%d. %s %s, %s, %s\n", i + 1, contato.nome, contato.sobrenome, contato.email, contato.telefone);
    }
}

void deletar_contato(Agenda *agenda) {
    char telefone_deletar[MAX_TELEFONE];
    printf("Digite o telefone do contato que deseja deletar: ");
    scanf("%s", telefone_deletar);

    for (int i = 0; i < agenda->quantidade_contatos; i++) {
        if (strcmp(agenda->contatos[i].telefone, telefone_deletar) == 0) {
            for (int j = i; j < agenda->quantidade_contatos - 1; j++) {
                agenda->contatos[j] = agenda->contatos[j + 1];
            }
            agenda->quantidade_contatos--;
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

void alterar_contato(Agenda *agenda) {
    char email_busca[MAX_EMAIL];
    printf("Digite o email do contato que deseja alterar: ");
    scanf("%s", email_busca);

    for (int i = 0; i < agenda->quantidade_contatos; i++) {
        if (strcmp(agenda->contatos[i].email, email_busca) == 0) {
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
                        scanf("%s", agenda->contatos[i].nome);
                        break;
                    case 2:
                        printf("Novo sobrenome: ");
                        scanf("%s", agenda->contatos[i].sobrenome);
                        break;
                    case 3:
                        printf("Novo email: ");
                        scanf("%s", agenda->contatos[i].email);
                        break;
                    case 4:
                        {
                            char novo_telefone[MAX_TELEFONE];
                            printf("Novo telefone: ");
                            scanf("%s", novo_telefone);
                            if (telefone_existe(agenda, novo_telefone)) {
                                printf("Erro: Telefone ja existe.\n");
                            } else {
                                strcpy(agenda->contatos[i].telefone, novo_telefone);
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
