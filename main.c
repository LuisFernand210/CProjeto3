#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main() {
    int opcao, tipo;
    Agenda agenda;
    inicializar_agenda(&agenda);

    do {
        printf("\n===== Menu =====\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Salvar agenda\n");
        printf("5. Carregar agenda\n");
        printf("6. Alterar contato\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao != 0 && opcao != 4 && opcao != 5) {
            printf("Selecione o tipo de contato:\n");
            printf("1. Pessoal\n");
            printf("2. Trabalho\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &tipo);
        }

        switch(opcao) {
            case 1:
                adicionar_contato(&agenda, tipo);
                break;
            case 2:
                listar_contatos(&agenda, tipo);
                break;
            case 3:
                deletar_contato(&agenda, tipo);
                break;
            case 4:
                salvar_agenda(&agenda);
                break;
            case 5:
                carregar_agenda(&agenda);
                break;
            case 6:
                alterar_contato(&agenda, tipo);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
