#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

    
    int k=0; //Contador para saber quantos inteiros tem o arquivo.
    int j=1000; //Variavel para aumentar de 1000 em 1000 a memoria alocada.
    int *num; //Memoria alocada dinamicamente.
/* -------------------------------------------------
	     DECLARA TODAS AS FUNÇÕES ANTES DA MAIN
   ------------------------------------------------- */

void gerar_arquivo(int arqc, char* arqv[])    //FUNÇÃO GERA ARQUIVO .OUT
{        
    FILE *arq2; //Define arquivo que irá ser escrito        
    arq2=fopen(arqv[arqc-1],"w");//cria o arquivo a ser escrito
    int numero;
    for(int i=1; i<arqc-1;i++) //Laço para ver os arquivos de entrada
    {   
        FILE *arq1; //Arquivo de entrada
        arq1=fopen(arqv[i],"r"); //abre o arquivo para leitura
      
        while(!feof(arq1)) //Enquanto não encontra o fim do arquivo
        { 
        fscanf(arq1,"%d",&numero); //lê do arquivo e salva em numero
        fprintf(arq2,"%d ",numero); //lê numero e salva no arquivo .OUT
        }
        fclose(arq1);//fecha o arquivo de leitura.
    }
    fclose(arq2); //Após ler todos os arquivos, fecha o arquivo .out

}

void vetoriza(int arqc, char* arqv[]){    // FUNÇÃO COLOCA TODOS OS DADOS DO ARQUIVO.OUT EM UM VETOR    
    
    FILE *arq; //Define arquivo que irá ser escrito.
    arq=fopen(arqv[arqc-1],"r");//Abre o arquivo a ser lido.

    num =(int *) calloc(1000,sizeof(int));//Aloca 1000 espaços inicialmente.

    while(!feof(arq)){
         fscanf(arq,"%d\n",&num[k]); //Lê todos os números do arquivo e salva em num.
         k++; //soma k para verificar quantos números(inteiros) possui o arquivo
         
         if(k==j) //k chegou ao limite da memoria alocada 
         {
           j=k+1000; //J recebe K+1000 para alocar K+1000
          num=realloc(num,j*sizeof(int));//Aloca k+1000
         }         
    
    }
     fclose(arq); //FECHA Arquivo

}

void quick_sort(int *a, int ini, int fim) {  //QUICK_SORT PARA ORDENA O VETOR
    int i, j, x, y;
    i = ini;
    j = fim;
    x = a[(ini + fim) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < fim) {
            i++;
        }
        while(a[j] > x && j > ini) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
    if(j > ini) {
        quick_sort(a, ini, j);
    }
    if(i < fim) {
        quick_sort(a, i, fim);
    }
}

void escrita(int arqc, char* arqv[]){

    FILE *arq; //Define arquivo que irá ser escrito.
    arq=fopen(arqv[arqc-1],"w");//Abre o arquivo a ser lido.
    for(int i=1;i<=k;i++)
      fprintf(arq,"%d ",num[i]);
    fclose(arq);
}

/* -------------------------------------------------
			    INICIO DA MAIN 
   ------------------------------------------------- */

    int main(int arqc,char* arqv[])
{       
   gerar_arquivo(arqc, arqv); //Chama função geradora do arquivo de saida sem ordenação.
   vetoriza(arqc,arqv); //Função para ler o arquivo e salva os dados no vetor num
   quick_sort(num,0 , k); //Ordena o vetor
   escrita(arqc,arqv);

    
     //ESCREVER ALGORITMO DE ORDENAÇÃO ANTES DE LIBERA MEMORIA  
    free(num);//libera memoria7

        return 0;

}