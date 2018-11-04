#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "arquivos.h"


int main(int arqc,char* arqv[])
{       
   //ler_vetoriza_arquivo(arqc, arqv);
    FILE *arq2; //Define arquivo que irá ser escrito        
    arq2=fopen(arqv[arqc-1],"w");//cria o arquivo a ser escrito

    for(int i=1; i<arqc;i++) //Laço para ver os arquivos de entrada
    {   
        FILE *arq1; //Arquivo de entrada
        arq1=fopen(arqv[i],"r"); //abre o arquivo para leitura
      
        while(!feof(arq1)) //Enquanto não encontra o fim do arquivo
        {
        int numero; 
        fscanf(arq1,"%d",&numero); //lê do arquivo e salva em numero
        fprintf(arq2,"%d ",numero); //lê numero e salva no arquivo novo
        }
        fclose(arq1);//fecha o arquivo de leitura.
    }

        return 0;

}