#ifndef AGENDA_MENU_TELEFONE_H
#define AGENDA_MENU_TELEFONE_H

#include <stdio.h>
#include <string.h>

#include "arquivo.h"
#include "modelo.h"

void crudTelefone();

void salvarTelefone();

void __salvarTelefone(Telefone*);

void editarTelefone();

void __editarTelefone(Telefone*);

void buscarTelefone();

void __buscarTelefone(int, Telefone*);

void excluirTelefone();

void __excluirTelefone(int);


#endif //AGENDA_MENU_TELEFONE_H
