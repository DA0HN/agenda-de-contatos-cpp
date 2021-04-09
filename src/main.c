/*Semana VIII - Projeto Final
O Projeto Final da disciplina de Algoritmos 2 deverá ser enviado desta vez, compactado em um único arquivo ZIP, RAR ou 7Z.

O objetivo da atividade é implementar uma Agenda Telefônica que contenha dados relacionados entre si.
Para isto, as informações deverão ser gravadas em arquivos, para o armazenamento em disco rígido, porém, é permitido que os arquivos sejam carregados em memória para facilitar a manipulação dos dados.

O que o sistema deve contemplar é o manutenção dos registros de uma Pessoa, porém esta pessoa pode conter mais de um telefone e mais de um e-mail.

Para resolver este problema, é necessário criar um arquivo para as Pessoas, um arquivo para os Telefones e um para os E-mails. Deste modo, é criado um índice que servira como identificador dos registros armazenados no arquivo.

Deste modo o sistema deve conter:
Cadastro/Edição/Exclusão de Pessoas
Cadastro/Edição/Exclusão de Telefones
Cadastro/Edição/Exclusão de E-mails
Consulta de Registros (Todos ou por id da pessoa)
*/

#include <stdio.h>

#include <stdlib.h>
#include <locale.h>
#include <string.h>


#include "menu.h"

int main() {
    // Deste modo o sistema deve conter:
    // Cadastro/Edição/Exclusão de Pessoas
    // Cadastro/Edição/Exclusão de Telefones
    // Cadastro/Edição/Exclusão de E-mails
    // Consulta de Registros (Todos ou por id da pessoa)
    menu();
}
