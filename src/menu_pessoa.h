#ifndef AGENDA_MENU_PESSOA_H
#define AGENDA_MENU_PESSOA_H

#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef struct Pessoa Pessoa;
typedef struct Email Email;
typedef struct Telefone Telefone;

void crudPessoa();

void salvarPessoa();

void __carregarTelefonePessoa();

void __carregarEmailPessoas();

void __carregarPessoas();

void __salvarPessoa(Pessoa *);

void editarPessoa();

void buscarPessoa();

int __buscarPessoa(int, Pessoa *);

void excluirPessoa();

void __excluirPessoa(size_t);

void excluirTelefonesPessoa(int);

void excluirEmailsPessoa(int);

void __excluirEmailPessoa(size_t);

void __excluirTelefonePessoa(int posicao);

void excluirTelefonesPessoa(int id);

void __filtraEmailsETelefones(int id, Telefone *telefones, Email *emails);

#endif //AGENDA_MENU_PESSOA_H
