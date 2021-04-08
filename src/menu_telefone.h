#ifndef AGENDA_MENU_TELEFONE_H
#define AGENDA_MENU_TELEFONE_H

#include <stdio.h>
#include <string.h>

#include "arquivo.h"
#include "modelo.h"

void crudTelefone();

void salvarTelefone();
void __salvarTelefone(Telefone* telefone);

void editarTelefone();
void __editarTelefone(Telefone* telefone);

void buscarTelefone();
void __buscarTelefone(int id, Telefone* telefone);

void excluirTelefone();
void __excluirTelefone(int id);




#endif //AGENDA_MENU_TELEFONE_H
