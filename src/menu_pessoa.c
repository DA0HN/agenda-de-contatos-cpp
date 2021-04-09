#include "menu_pessoa.h"
#include "arquivo.h"
#include "modelo.h"

Pessoa pessoas[QUANTIDADE_PESSOAS];
Email pessoas_email[QUANTIDADE_EMAILS];
Telefone pessoas_telefone[QUANTIDADE_TELEFONES];

void salvarPessoa() {
    Pessoa pessoa;


    printf("Digite o id da pessoa: ");
    scanf("%d", &pessoa.idPessoa);

    setbuf(stdin, NULL);

    printf("Digite o nome: ");
    scanf("%50s[^\n]", pessoa.nome); //20-> qtde de caractere

    __salvarPessoa(&pessoa);
}


void __salvarPessoa(Pessoa *pessoa) {
    FILE *arquivo = abreArquivo('a', CAMINHO_PESSOA);
    fprintf(arquivo, "%d ", pessoa->idPessoa);
    fprintf(arquivo, "%s\n", pessoa->nome);
    fecharArquivo(arquivo);
}

void __carregarEmailPessoas() {
    FILE *arquivo = abreArquivo('l', CAMINHO_EMAIL);

    for (size_t i = 0; i < QUANTIDADE_PESSOAS; i++) pessoas_email[i].idEmail = -1;

    int i = 0;
    while (!feof(arquivo)) {
        setbuf(stdin, NULL);
        fscanf(arquivo, "%d", &pessoas_email[i].idEmail);
        fscanf(arquivo, "%d", &pessoas_email[i].idPessoa);
        fscanf(arquivo, "%s", pessoas_email[i].email);
        i++;
    }
    fecharArquivo(arquivo);
}

void __carregarTelefonePessoa() {

    FILE *arquivo = abreArquivo('l', CAMINHO_TELEFONE);

    for (size_t i = 0; i < QUANTIDADE_PESSOAS; i++) pessoas_telefone[i].idTelefone = -1;

    int i = 0;
    while (!feof(arquivo)) {
        setbuf(stdin, NULL);
        fscanf(arquivo, "%d", &pessoas_telefone[i].idTelefone);
        fscanf(arquivo, "%d", &pessoas_telefone[i].idPessoa);
        fscanf(arquivo, "%s", pessoas_telefone[i].telefone);
        i++;
    }
    fecharArquivo(arquivo);
}

void __carregarPessoas() {

    FILE *arquivo = abreArquivo('l', CAMINHO_PESSOA);

    for (size_t i = 0; i < QUANTIDADE_PESSOAS; i++) pessoas[i].idPessoa = -1;

    int i = 0;
    while (!feof(arquivo)) {
        setbuf(stdin, NULL);
        fscanf(arquivo, "%d", &pessoas[i].idPessoa);
        fscanf(arquivo, "%s", pessoas[i].nome);

        i++;
    }
    fecharArquivo(arquivo);
}

void editarPessoa() {
    int id;
    printf("Digite o id da pessoa: ");
    scanf("%d", &id);

    __carregarPessoas();

    int contador = 0;

    while (contador < 20) {
        if (id == pessoas[contador].idPessoa) {
            printf("Informe novo nome para pessoa: ");
            scanf("%50s[^\n]", pessoas[contador].nome);
            break;
        }
        contador++;
    }

    contador = 0;
    FILE *arquivo = abreArquivo('g', CAMINHO_PESSOA);

    while (contador < QUANTIDADE_PESSOAS) {
        if (pessoas[contador].idPessoa != -1) {
            __salvarPessoa(&pessoas[contador]);
        }
        contador++;
    }
    fecharArquivo(arquivo);
}


void __excluirPessoa(size_t posicao) {
    for (size_t i = posicao; i < QUANTIDADE_PESSOAS - 1; i++) {
        pessoas[i] = pessoas[i + 1];
    }
}

void excluirPessoa() {
    int id;
    printf("Digite o id da pessoa: ");
    scanf("%d", &id);

    __carregarPessoas();

    size_t posicao = 0;

    while (posicao < QUANTIDADE_PESSOAS) {
        if (id == pessoas[posicao].idPessoa) {
            break;
        }
        posicao++;
    }
    __excluirPessoa(posicao);
    excluirTelefonesPessoa(id);
    excluirEmailsPessoa(id);

    FILE *arquivoPessoa = abreArquivo('g', CAMINHO_PESSOA);
    size_t contador = 0;


    while (contador < QUANTIDADE_PESSOAS) {
        if (pessoas[contador].idPessoa != -1) {
            __salvarPessoa(&pessoas[contador]);
        }
        contador++;
    }
    fecharArquivo(arquivoPessoa);
}


void __excluirEmailPessoa(size_t posicao) {
    for (int i = posicao; i < QUANTIDADE_PESSOAS - 1; i++) {
        pessoas_email[i] = pessoas_email[i + 1];
    }
}

void excluirEmailsPessoa(int id) {

    __carregarEmailPessoas();

    for (int posicao = 0; posicao < QUANTIDADE_PESSOAS; posicao++) {
        if (id == pessoas_email[posicao].idPessoa) {

            __excluirEmailPessoa(posicao);
            posicao = -1;
        }
    }

    FILE *arquivoEmail = abreArquivo('g', CAMINHO_EMAIL);
    for (int contador = 0; contador < QUANTIDADE_PESSOAS; contador++) {
        if (pessoas_email[contador].idEmail != -1) {
            fprintf(arquivoEmail, "%d %d %s\n",
                    pessoas_email[contador].idEmail,
                    pessoas_email[contador].idPessoa,
                    pessoas_email[contador].email
            );
        }
    }
    fecharArquivo(arquivoEmail);
}

void __excluirTelefonePessoa(int posicao) {
    for (int i = posicao; i < QUANTIDADE_PESSOAS - 1; i++) {
        pessoas_telefone[i] = pessoas_telefone[i + 1];
    }
}

void excluirTelefonesPessoa(int id) {
    __carregarTelefonePessoa();

    for (int posicao = 0; posicao < QUANTIDADE_PESSOAS; posicao++) {
        if (id == pessoas_telefone[posicao].idPessoa) {
            __excluirTelefonePessoa(posicao);
            posicao = -1;
        }
    }

    FILE *arquivoTelefone = abreArquivo('g', CAMINHO_TELEFONE);
    size_t contador = 0;
    while (contador < QUANTIDADE_PESSOAS) {
        if (pessoas_telefone[contador].idTelefone != -1) {
            fprintf(arquivoTelefone, "%d %d %s\n",
                    pessoas_telefone[contador].idTelefone,
                    pessoas_telefone[contador].idPessoa,
                    pessoas_telefone[contador].telefone
            );
        }
        contador++;
    }
    fecharArquivo(arquivoTelefone);
}

void crudPessoa() {
    int sair = 0;

    do {
        int opcao;

        printf("\n1 - Cadastrar pessoa\n");
        printf("2 - Editar pessoa\n");
        printf("3 - Busca pessoa\n");
        printf("4 - Exclui pessoa\n");
        printf("5 - Voltar ao menu inicial\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Cria um novo telefone
                salvarPessoa();
                break;
            case 2:
                // Altera um telefone
                editarPessoa();
                break;
            case 3:
                // Consulta telefone por id
                //buscarEmail();
                break;
            case 4:
                // Exclui telefone
                excluirPessoa();
                break;
            case 5:
                // Retorna ao menu inicial
                sair = 1;
                break;
        }
    } while (sair != 1);
}
