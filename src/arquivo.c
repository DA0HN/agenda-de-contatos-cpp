#include "arquivo.h"

const char *EMAIL = "/home/daohn/Documentos/code/agenda/email.txt";
const char *PESSOA = "/home/daohn/Documentos/code/agenda/pessoa.txt";


FILE *abreArquivo(char modo, char caminho[100]) { //funcao
    FILE *arquivo;
    switch (modo) {
        case 'g':
            arquivo = fopen(caminho, "wt");
            break;
        case 'l':
            arquivo = fopen(caminho, "rt");
            break;
        case 'a':
            arquivo = fopen(caminho, "a");
            break;
    }
    if (arquivo == NULL) {      //Se houver algum erro, o ponteiro apontará para NULL
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}


void fecharArquivo(FILE *arquivo) {
    fclose(arquivo);
}
