#include "menu_telefone.h"
#include "arquivo.h"
#include "modelo.h"

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
    FILE *arquivo = abreArquivo('a', CAMINHO_TELEFONE);
    fprintf(arquivo, "%d %d %s\n",
            telefone->idTelefone,
            telefone->idPessoa,
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

    FILE *arquivo = abreArquivo('l', CAMINHO_TELEFONE);
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

    FILE *arquivo = abreArquivo('l', CAMINHO_TELEFONE);

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
    FILE *arquivo = abreArquivo('g', CAMINHO_TELEFONE);

    while ((contador++) < QUANTIDADE_TELEFONES) {
        if (telefones[contador].idTelefone != -1) {
            __salvarTelefone(&telefones[contador]);
        }
    }
    fecharArquivo(arquivo);
}

void __excluirTelefone(size_t posicao) {
    for (size_t i = posicao; i < QUANTIDADE_TELEFONES - 1; i++) {
        telefones[i] = telefones[i + 1];
    }
}

void excluirTelefone() {
    int id;
    printf("Digite o id do telefone: ");
    scanf("%d", &id);

    __carregarTelefones();

    size_t posicao = 0;

    while (posicao < QUANTIDADE_TELEFONES) {
        if (id == telefones[posicao].idTelefone) {
            break;
        }
        posicao++;
    }
    __excluirTelefone(posicao);

    FILE *arquivo = abreArquivo('g', CAMINHO_TELEFONE);
    size_t contador = 0;

    while (contador < QUANTIDADE_TELEFONES) {
        if (telefones[contador].idTelefone != -1) {
            __salvarTelefone(&telefones[contador]);
        }
        contador++;
    }
    fecharArquivo(arquivo);
}

void crudTelefone() {
    int sair = 0;

    do {
        int opcao;

        printf("\n1 - Cadastrar telefone\n");
        printf("2 - Editar telefone\n");
        printf("3 - Busca telefone\n");
        printf("4 - Exclui telefone\n");
        printf("5 - Voltar ao menu inicial\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Cria um novo telefone
                salvarTelefone();
                break;
            case 2:
                // Altera um telefone
                alteraTelefone();
                break;
            case 3:
                // Consulta telefone por id
                buscarTelefone();
                break;
            case 4:
                // Exclui telefone
                excluirTelefone();
                break;
            case 5:
                // Retorna ao menu inicial
                sair = 1;
                break;
        }
    } while (sair == 1);
}