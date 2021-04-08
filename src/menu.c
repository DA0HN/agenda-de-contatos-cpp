#include <stdio.h>
#include <string.h>

#include "arquivo.c"

typedef struct Email
{
  int idEmail;
  int idPessoa;
  char email[30];
} Email;

typedef struct Telefone
{
  int idTelefone;
  int idPessoa;
  char telefone[20];
} Telefone;

typedef struct Pessoa
{
  int idPessoa;
  char nome[50];
} Pessoa;

void mostrarMenu();
void crudTelefone();

void salvarTelefone();
void __salvarTelefone(Telefone* telefone);

void editarTelefone();
void __editarTelefone(Telefone* telefone);

void buscarTelefone();
void __buscarTelefone(int id, Telefone* telefone);

void excluirTelefone();
void __excluirTelefone(int id);

Telefone telefones[20];

void salvarTelefone() {
  printf("Digite o id: ");
  scanf("%d", &telefone.idTelefone);
  printf("Digite o id da pessoa: ");
  scanf("%d", &telefone.idPessoa);

  setbuf(stdin, NULL);

  printf("Digite o telefone: ");
  scanf("%20s[^\n]", &telefone.telefone); //20-> qtde de caractere

  salvarTelefone(&telefone);
}


void __salvarTelefone(Telefone* telefone){
    FILE* arquivo = abreArquivo('a', "telefone.txt");
    fprintf(arquivo, "%d %d %s\n\r",
        telefone->idPessoa,
        telefone->idTelefone,
        telefone->telefone
    );
    fecharArquivo(arquivo);
}

void buscarTelefone() {
  int id;
  printf("Digite o id do telefone: ");
  scanf("%d", &id);

  Telefone telefone;

  __buscarTelefone(id, &telefone);

  printf("Id: %d\n", telefone.idTelefone);
  printf("Pessoa: %d\n", telefone.idPessoa);
  printf("Telefone: %s\n", telefone.telefone);
}

void __buscarTelefone(int id, Telefone* telefone) {

  FILE* arquivo = abreArquivo('l', "telefone.txt");
  int flag = 0;
  while(!feof(arquivo)) {
    setbuf(stdin, NULL);
    fscanf(arquivo, "%d", &telefone->idPessoa);
    fscanf(arquivo, "%d", &telefone->idTelefone);
    fscanf(arquivo, "%s", &telefone->telefone);

    if(id == arquivo->idTelefone) {
      flag = 1;
      break;
    }
  }

  if(flag) {
    printf("Telefone encontrado!\n");
  }
  else {
    printf("Telefone nao encontrado!\n");
  }

  fecharArquivo(arquivo);
}

void __carregarTelefones() {

  FILE* arquivo = abreArquivo('l', "telefone.txt");
  int i = 0;

  while(!feof(arquivo)) {
    setbuf(stdin, NULL);
    fscanf(arquivo, "%d %d %s", &telefones[i].idPessoa, &telefones[i].idTelefone, &telefones[i].telefone);
    i++;
  }
  fecharArquivo(arquivo);
}

void alteraTelefone() {
  int id;
  printf("Digite o id do telefone: ");
  scanf("%d", &id);

  Telefone telefone;

  __carregarTelefones();

  int contador = 0;

  while((contador++) < 20) {

    if(id == telefones[contador].idTelefone) {
      printf("Insira o novo telefone: ");
      scanf("%20s[^\n]", telefones[contador].telefone);
      break;
    }
  }

  contador = 0;
  FILE* arquivo = abreArquivo('g', "telefone.txt");

  while((contador++) < 20) {
    __salvarTelefone(telefones[contador]);
  }
  fecharArquivo(arquivo);
}

void excluirTelefone() {
  int id;
  printf("Digite o id do telefone: ");
  scanf("%d", &id);

  Telefone telefone;

  __carregarTelefones();

  int contador = 0;

  while((contador++) < 20) {
    if(id == telefones[contador].idTelefone) {
      telefones[contador] = NULL;
      break;
    }
  }

  contador = 0;
  FILE* arquivo = abreArquivo('g', "telefone.txt");

  while((contador++) < 20) {
    __salvarTelefone(telefones[contador]);
  }
  fecharArquivo(arquivo);
}

void mostrarMenu() {
    printf("\nMENU:");
    printf("\n1 - Cadastrar usuario");
    printf("\n2 - Editar usuario");
    printf("\n3 - exluir usuario");
    printf("\n4 - sair");
}

void crudTelefone() {
    int opcao;
    Telefone telefone;

    printf("\n1 - Cadastrar telefone");
    printf("\n2 - Editar telefone");
    printf("\n3 - Busca telefone");
    printf("\n4 - Exclui telefone");
    printf("\n5 - Voltar ao menu inicial");

    scanf("%d", &opcao);

    switch(opcao){
    // Cria um novo telefone
    case 1:
      salvarTelefone();
      break;
    // Altera um telefone
    case 2:
      alteraTelefone();
      break;
    // Consulta telefone por id
    case 3:
      buscarTelefone();
      break;
    // // Exclui telefone
    case 4:
      excluirTelefone();
      break;
  }
}

void menu() {
    // Pessoa p;
    // int opcao;
    //
    // scanf("%d", &opcao);
    //
    // switch(opcao){
    //     case 1:
    //     printf("Digite o nome");
    //     scanf("%s\n", &p.nome);
    //
    //     break;
    //
    //     case 2:
    //     break;
    //
    //     case 3:
    //     break;
    //
    //     case 4:
    //     break;
    // }
}
