#include "menu_email.h"
#include "arquivo.h"
#include "modelo.h"

Email emails[QUANTIDADE_EMAILS];

void salvarEmail() {
    Email email;


    printf("Digite o id: ");
    scanf("%d", &email.idEmail);
    printf("Digite o id da pessoa: ");
    scanf("%d", &email.idPessoa);

    setbuf(stdin, NULL);

    printf("Digite o email: ");
    scanf("%30s[^\n]", email.email); //20-> qtde de caractere

    __salvarEmail(&email);
}


void __salvarEmail(Email *email) {
    FILE *arquivo = abreArquivo('a', CAMINHO_EMAIL);
    fprintf(arquivo, "%d %d %s\n",
            email->idEmail,
            email->idPessoa,
            email->email
    );
    fecharArquivo(arquivo);
}

void buscarEmail() {
    int id;
    int encontrado;
    printf("Digite o id do email: ");
    scanf("%d", &id);

    Email email;

    encontrado = __buscarEmail(id, &email);

    if(encontrado == 1){
      printf("Id: %d\n", email.idEmail);
      printf("Pessoa: %d\n", email.idPessoa);
      printf("Email: %s\n", email.email);
    }
}

int __buscarEmail(int id, Email *email) {

    FILE *arquivo = abreArquivo('l', CAMINHO_EMAIL);
    int flag = 0;
    while (!feof(arquivo)) {
        setbuf(stdin, NULL);
        fscanf(arquivo, "%d %d %s", &email->idEmail, &email->idPessoa, email->email);
        if (id == email->idEmail) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Email encontrado!\n");
    } else {
        printf("Email nao encontrado!\n");
    }

    fecharArquivo(arquivo);
    return flag;
}

void __carregarEmails() {

    FILE *arquivo = abreArquivo('l', CAMINHO_EMAIL);

    for (size_t i = 0; i < QUANTIDADE_EMAILS; i++) emails[i].idEmail = -1;

    int i = 0;
    while (!feof(arquivo)) {
        setbuf(stdin, NULL);
        fscanf(arquivo, "%d", &emails[i].idEmail);
        fscanf(arquivo, "%d", &emails[i].idPessoa);
        fscanf(arquivo, "%s", emails[i].email);
        i++;
    }
    fecharArquivo(arquivo);
}

void alteraEmail() {
    int id;
    printf("Digite o id do email: ");
    scanf("%d", &id);

    __carregarEmails();

    int contador = 0;

    while ((contador++) < 20) {
        if (id == emails[contador].idEmail) {
            printf("Insira o novo email: ");
            scanf("%30s[^\n]", emails[contador].email);
            break;
        }
    }

    contador = 0;
    FILE *arquivo = abreArquivo('g', CAMINHO_EMAIL);

    while ((contador++) < QUANTIDADE_EMAILS) {
        if (emails[contador].idEmail != -1) {
            __salvarEmail(&emails[contador]);
        }
    }
    fecharArquivo(arquivo);
}

void __excluirEmail(size_t posicao) {
    for (size_t i = posicao; i < QUANTIDADE_EMAILS - 1; i++) {
        emails[i] = emails[i + 1];
    }
}

void excluirEmail() {
    int id;
    printf("Digite o id do email: ");
    scanf("%d", &id);

    __carregarEmails();

    size_t posicao = 0;

    while (posicao < QUANTIDADE_EMAILS) {
        if (id == emails[posicao].idEmail) {
            break;
        }
        posicao++;
    }
    __excluirEmail(posicao);

    FILE *arquivo = abreArquivo('g', CAMINHO_EMAIL);
    size_t contador = 0;

    while (contador < QUANTIDADE_EMAILS) {
        if (emails[contador].idEmail != -1) {
            __salvarEmail(&emails[contador]);
        }
        contador++;
    }
    fecharArquivo(arquivo);
}

void crudEmail() {
    int sair = 0;

    do {
        int opcao;

        printf("\n1 - Cadastrar email\n");
        printf("2 - Editar email\n");
        printf("3 - Busca email\n");
        printf("4 - Exclui email\n");
        printf("5 - Voltar ao menu inicial\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Cria um novo telefone
                salvarEmail();
                break;
            case 2:
                // Altera um telefone
                alteraEmail();
                break;
            case 3:
                // Consulta telefone por id
                buscarEmail();
                break;
            case 4:
                // Exclui telefone
                excluirEmail();
                break;
            case 5:
                // Retorna ao menu inicial
                sair = 1;
                break;
        }
    } while (sair != 1);
}
