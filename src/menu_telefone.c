#include "menu_telefone.h"

#define QUANTIDADE_TELEFONES 20

char *TELEFONE = "/home/daohn/Documentos/code/agenda/telefone.txt";

Telefone telefones[QUANTIDADE_TELEFONES];

void salvarTelefone() {
    Telefone telefone;


    printf("Digite o id: ");
    scanf("%d", &telefone.idTelefone);
    printf("Digite o id da pessoa: ");
    scanf("%d", &telefone.idPessoa);

    setbuf(stdin, NULL);

    printf("Digite o telefone: ");
    scanf("%20s[^\n]", telefone.telefone); //20-> qtde de caractere

    __salvarTelefone(&telefone);
}


void __salvarTelefone(Telefone *telefone) {
    FILE *arquivo = abreArquivo('a', TELEFONE);
    fprintf(arquivo, "%d %d %s\n",
            telefone->idPessoa,
            telefone->idTelefone,
            telefone->telefone
    );
    fecharArquivo(arquivo);
}

void buscarTelefone() {
    int id;
    printf("Digite o id do telefone: ");
    scanf("%d", &id);

    Telefone telefone;

    __buscarTelefone(id, &telefone);

    printf("Id: %d\n", telefone.idTelefone);
    printf("Pessoa: %d\n", telefone.idPessoa);
    printf("Telefone: %s\n", telefone.telefone);
}

void __buscarTelefone(int id, Telefone *telefone) {

    FILE *arquivo = abreArquivo('l', TELEFONE);
    int flag = 0;
    while (!feof(arquivo)) {
        setbuf(stdin, NULL);
        fscanf(arquivo, "%d %d %s", &telefone->idTelefone, &telefone->idPessoa, telefone->telefone);
        if (id == telefone->idTelefone) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Telefone encontrado!\n");
    } else {
        printf("Telefone nao encontrado!\n");
    }

    fecharArquivo(arquivo);
}

void __carregarTelefones() {

    FILE *arquivo = abreArquivo('l', TELEFONE);

    for (size_t i = 0; i < QUANTIDADE_TELEFONES; i++) telefones[i].idTelefone = -1;

    int i = 0;
    while (!feof(arquivo)) {
        setbuf(stdin, NULL);
        fscanf(arquivo, "%d", &telefones[i].idTelefone);
        fscanf(arquivo, "%d", &telefones[i].idPessoa);
        fscanf(arquivo, "%s", telefones[i].telefone);
        i++;
    }
    fecharArquivo(arquivo);
}

void alteraTelefone() {
    int id;
    printf("Digite o id do telefone: ");
    scanf("%d", &id);

    __carregarTelefones();

    int contador = 0;

    while ((contador++) < 20) {
        if (id == telefones[contador].idTelefone) {
            printf("Insira o novo telefone: ");
            scanf("%20s[^\n]", telefones[contador].telefone);
            break;
        }
    }

    contador = 0;
    FILE *arquivo = abreArquivo('g', TELEFONE);

    while ((contador++) < 20) {
        if (telefones[contador].idTelefone != -1) {
            __salvarTelefone(&telefones[contador]);
        }
    }
    fecharArquivo(arquivo);
}

void excluirTelefone() {
    int id;
    printf("Digite o id do telefone: ");
    scanf("%d", &id);

    Telefone telefone;

    __carregarTelefones();

    int contador = 0;

    while ((contador++) < 20) {
        if (id == telefones[contador].idTelefone) {

        }
    }

    contador = 0;
    FILE *arquivo = abreArquivo('g', TELEFONE);

    while ((contador++) < 20) {
        __salvarTelefone(&telefones[contador]);
    }
    fecharArquivo(arquivo);
}

void crudTelefone() {
    int opcao;

    printf("\n1 - Cadastrar telefone\n");
    printf("2 - Editar telefone\n");
    printf("3 - Busca telefone\n");
    printf("4 - Exclui telefone\n");
    printf("5 - Voltar ao menu inicial\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        // Cria um novo telefone
        case 1:
            salvarTelefone();
            break;
        // Altera um telefone
        case 2:
            alteraTelefone();
            break;
        // Consulta telefone por id
        case 3:
            buscarTelefone();
            break;
        // Exclui telefone
        case 4:
            excluirTelefone();
            break;
    }
}