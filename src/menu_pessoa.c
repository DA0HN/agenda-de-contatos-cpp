#include "menu_pessoa.h"
#include "arquivo.h"
#include "modelo.h"

Pessoa pessoas[QUANTIDADE_PESSOAS];
Email pessoasEmail[QUANTIDADE_EMAILS];
Telefone pessoasTelefone[QUANTIDADE_TELEFONES];

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

    for (size_t i = 0; i < QUANTIDADE_PESSOAS; i++) pessoasEmail[i].idEmail = -1;

    int i = 0;
    while (!feof(arquivo)) {
        setbuf(stdin, NULL);
        fscanf(arquivo, "%d", &pessoasEmail[i].idEmail);
        fscanf(arquivo, "%d", &pessoasEmail[i].idPessoa);
        fscanf(arquivo, "%s", pessoasEmail[i].email);
        i++;
    }
    fecharArquivo(arquivo);
}

void __carregarTelefonePessoa() {

    FILE *arquivo = abreArquivo('l', CAMINHO_TELEFONE);

    for (size_t i = 0; i < QUANTIDADE_PESSOAS; i++) pessoasTelefone[i].idTelefone = -1;

    int i = 0;
    while (!feof(arquivo)) {
        setbuf(stdin, NULL);
        fscanf(arquivo, "%d", &pessoasTelefone[i].idTelefone);
        fscanf(arquivo, "%d", &pessoasTelefone[i].idPessoa);
        fscanf(arquivo, "%s", pessoasTelefone[i].telefone);
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

    while (contador < QUANTIDADE_PESSOAS) {
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
        pessoasEmail[i] = pessoasEmail[i + 1];
    }
}

void excluirEmailsPessoa(int id) {

    __carregarEmailPessoas();

    for (int posicao = 0; posicao < QUANTIDADE_PESSOAS; posicao++) {
        if (id == pessoasEmail[posicao].idPessoa) {

            __excluirEmailPessoa(posicao);
            posicao = -1;
        }
    }

    FILE *arquivoEmail = abreArquivo('g', CAMINHO_EMAIL);
    for (int contador = 0; contador < QUANTIDADE_PESSOAS; contador++) {
        if (pessoasEmail[contador].idEmail != -1) {
            fprintf(arquivoEmail, "%d %d %s\n",
                    pessoasEmail[contador].idEmail,
                    pessoasEmail[contador].idPessoa,
                    pessoasEmail[contador].email
            );
        }
    }
    fecharArquivo(arquivoEmail);
}

void __excluirTelefonePessoa(int posicao) {
    for (int i = posicao; i < QUANTIDADE_PESSOAS - 1; i++) {
        pessoasTelefone[i] = pessoasTelefone[i + 1];
    }
}

void excluirTelefonesPessoa(int id) {
    __carregarTelefonePessoa();

    for (int posicao = 0; posicao < QUANTIDADE_PESSOAS; posicao++) {
        if (id == pessoasTelefone[posicao].idPessoa) {
            __excluirTelefonePessoa(posicao);
            posicao = -1;
        }
    }

    FILE *arquivoTelefone = abreArquivo('g', CAMINHO_TELEFONE);
    size_t contador = 0;
    while (contador < QUANTIDADE_PESSOAS) {
        if (pessoasTelefone[contador].idTelefone != -1) {
            fprintf(arquivoTelefone, "%d %d %s\n",
                    pessoasTelefone[contador].idTelefone,
                    pessoasTelefone[contador].idPessoa,
                    pessoasTelefone[contador].telefone
            );
        }
        contador++;
    }
    fecharArquivo(arquivoTelefone);
}

int __buscarPessoa(int id, Pessoa *pessoa) {

    FILE *arquivo = abreArquivo('l', CAMINHO_PESSOA);

    int pessoaEncontrada = 0;
    while (!feof(arquivo)) {
        setbuf(stdin, NULL);
        fscanf(arquivo, "%d %s", &pessoa->idPessoa, pessoa->nome);

        if (id == pessoa->idPessoa) {
            pessoaEncontrada = 1;
            break;
        }
    }

    if (pessoaEncontrada) {
        printf("Pessoa encontrada!\n");
    } else {
        printf("Pessoa nao encontrada!\n");
    }

    fecharArquivo(arquivo);
    return pessoaEncontrada;
}

void buscarPessoa() {
    int id;
    printf("Digite o id da pessoa: ");
    scanf("%d", &id);

    Pessoa pessoa;

    int encontrado = __buscarPessoa(id, &pessoa);

    if (encontrado) {
        __pessoaEncontrada(id, &pessoa);
    }
}

void __pessoaEncontrada(int id, Pessoa *pessoa) {
    Telefone telefonesDaPessoa[QUANTIDADE_TELEFONES];
    Email emailsDaPessoa[QUANTIDADE_PESSOAS];

    for (int i = 0; i < QUANTIDADE_TELEFONES; i++) telefonesDaPessoa[i].idPessoa = -1;
    for (int i = 0; i < QUANTIDADE_TELEFONES; i++) emailsDaPessoa[i].idPessoa = -1;

    __filtraEmailsETelefones(id, telefonesDaPessoa, emailsDaPessoa);

    printf("Id: %d\n", pessoa->idPessoa);
    printf("Nome: %s\n", pessoa->nome);

    printf("Telefones:\n");
    for (size_t i = 0; i < QUANTIDADE_TELEFONES; i++) {
        if (telefonesDaPessoa[i].idPessoa != -1) {
            printf("%s\n", telefonesDaPessoa[i].telefone);
        }
    }

    printf("Emails:\n");
    for (size_t i = 0; i < QUANTIDADE_EMAILS; i++) {
        if (emailsDaPessoa[i].idPessoa != -1) {
            printf("%s\n", emailsDaPessoa[i].email);
        }
    }
}

void __filtraEmailsETelefones(int id, Telefone telefones[QUANTIDADE_TELEFONES], Email emails[QUANTIDADE_PESSOAS]) {
    __carregarEmailPessoas();
    __carregarTelefonePessoa();

    // Filtra telefones relacionados à pessoa
    for (size_t i = 0, j = 0; i < QUANTIDADE_TELEFONES; i++) {
        if (pessoasTelefone[i].idPessoa == id) {
            telefones[j++] = pessoasTelefone[i];
        }
    }
    // Filtra emails relacionados à pessoa
    for (size_t i = 0, j = 0; i < QUANTIDADE_PESSOAS; i++) {
        if (pessoasEmail[i].idPessoa == id) {
            emails[j++] = pessoasEmail[i];
        }
    }
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
                // Cria um novo pessoa
                salvarPessoa();
                break;
            case 2:
                // Altera um pessoa
                editarPessoa();
                break;
            case 3:
                // Consulta pessoa por id
                buscarPessoa();
                break;
            case 4:
                // Exclui pessoa
                excluirPessoa();
                break;
            case 5:
                // Retorna ao menu inicial
                sair = 1;
                break;
        }
    } while (sair != 1);
}
