#ifndef MODELO_H
#define MODELO_H

typedef struct Email {
    int idEmail;
    int idPessoa;
    char email[30];
} Email;

typedef struct Telefone {
    int idTelefone;
    int idPessoa;
    char telefone[20];
} Telefone;

typedef struct Pessoa {
    int idPessoa;
    char nome[50];
} Pessoa;

#define CAMINHO_PESSOA  "/home/daohn/Documentos/code/agenda/pessoa.txt"
#define CAMINHO_TELEFONE  "/home/daohn/Documentos/code/agenda/telefone.txt"
#define CAMINHO_EMAIL  "/home/daohn/Documentos/code/agenda/email.txt"

#define QUANTIDADE_PESSOAS 20
#define QUANTIDADE_EMAILS 20
#define QUANTIDADE_TELEFONES 20

#endif // MODELO_H