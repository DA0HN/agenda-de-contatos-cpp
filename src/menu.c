#include "menu.h"

void menu() {

    int opcao;

    int sair = 0;

    do {
        printf("\nMENU:\n");
        printf("1 - Menu pessoa\n");
        printf("2 - Menu email\n");
        printf("3 - Menu telefone\n");
        printf("4 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                crudPessoa();
                break;
            case 2:
                crudEmail();
                break;
            case 3:
                crudTelefone();
                break;
            case 4:
                sair = 1;
                break;
        }
    } while (sair == 0);
}
