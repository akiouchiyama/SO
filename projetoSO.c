#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "vetoriza.h"
#include "gerar.h"


int main(int arqc,char* arqv[])
{       
   gerar_arquivo(arqc, arqv); //gerar arquivo de saida sem ordenação.
   vetoriza(arqc,arqv); //Função para ler o arquivo e armazena em uma variavel
        return 0;

}