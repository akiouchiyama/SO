#include "arquivos.h"
#include <stdio.h>

void ler_vetoriza_arquivo(char* arqv[])   
{       
    int tam=sizeof(arqv)/sizeof(argv[]); 
    for(int i=1; i<=tam;i++)
        fopen(arqv[i],r); //abre o arquivo para ler.
        fopen(arq[tam],a);
    fscanf(arq[i],"%d",arq[tam]);
}