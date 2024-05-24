#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main() {
    int opcao;
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

        switch(opcao) {
            case 1:
                adicionar_contato(&agenda);
                break;
            case 2:
                listar_contatos(&agenda);
                break;
            case 3:
                deletar_contato(&agenda);
                break;
            case 4:
                salvar_agenda(&agenda);
                break;
            case 5:
                carregar_agenda(&agenda);
                break;
            case 6:
                alterar_contato(&agenda);
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
