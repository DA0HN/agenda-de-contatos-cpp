#include "menu.h"

void menu() {

    int opcao;

    int sair = 0;

    do {
        printf("\nMENU:");
        printf("\n1 - Menu pessoa");
        printf("\n2 - Menu email");
        printf("\n3 - Menu telefone");
        printf("\n4 - Sair");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // crudPessoa();
                break;
            case 2:
                // crudEmail();
                break;
            case 3:
                crudTelefone();
                break;
            case 4:
                sair = 1;
                break;
        }
    } while(sair == 0);
}
