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

#endif // MODELO_H