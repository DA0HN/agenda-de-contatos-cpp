#ifndef AGENDA_MENU_PESSOA_H
#define AGENDA_MENU_PESSOA_H

#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef struct Pessoa Pessoa;
typedef struct Email Email;

void crudPessoa();

void salvarPessoa();

void __carregarTelefonePessoa();

void __carregarEmailPessoas();

void __carregarPessoas();

void __salvarPessoa(Pessoa *);

void editarPessoa();

void __editarPessoa(Pessoa *);

void buscarPessoa();

int __buscarPessoa(int, Pessoa *);

void excluirPessoa();

void __excluirPessoa(size_t);

void excluirTelefonesPessoa(int);

void excluirEmailsPessoa(int);

void __excluirEmailPessoa(size_t);

void  __salvarEmailPessoa(Email *);


#endif //AGENDA_MENU_PESSOA_H
