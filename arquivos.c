#include <stdio.h>
#include <string.h>

void ler_vetoriza_arquivo(int arqc, char* arqv[])   
{        
    FILE *arq2; //Define arquivo que irá ser escrito        
    arq2=fopen(arqv[arqc-1],"w");//cria o arquivo a ser escrito
    for(int i=1; i<arqc;i++) //Laço para ver os arquivos de entrada
    {   
        FILE *arq1; //Arquivo de entrada
        arq1=fopen(arqv[i],"r"); //abre o arquivo para leitura
        do{
        int numero; 
        fscanf(arq1,"%d\n",&numero); //lê do arquivo e salva em numero
        fprintf(arq2,"%d\n",numero); //lê numero e salva no arquivo novo
        }while(!feof(arq1));//Enquanto não encontra o fim do arquivo

        fclose(arq1);//fecha o arquivo de leitura.
    }

}