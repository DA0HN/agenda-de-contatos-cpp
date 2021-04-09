#ifndef AGENDA_MENU_EMAIL_H
#define AGENDA_MENU_EMAIL_H

#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef struct Email Email;

void crudEmail();

void salvarEmail();

void __salvarEmail(Email *);

void editarEmail();

void __editarEmail(Email *);

void buscarEmail();

int __buscarEmail(int, Email *);

void excluirEmail();

void __excluirEmail(size_t);


#endif //AGENDA_MENU_EMAIL_H
