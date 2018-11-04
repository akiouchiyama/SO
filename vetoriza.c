#include <stdio.h>
#include <stdlib.h> 

void vetoriza(int arqc, char* arqv[]){        
    
    FILE *arq; //Define arquivo que irá ser escrito.
    arq=fopen(arqv[arqc-1],"rw");//cria o arquivo a ser escrito.

    int k=0; //Contador para saber quantos inteiros tem o arquivo.
    int j=1000; //Variavel para aumentar de 1000 em 1000 a memoria alocada.
    int *num; //Memoria alocada dinamicamente.
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
    
     //ESCREVER ALGORITMO DE ORDENAÇÃO ANTES DE LIBERA MEMORIA  
    free(num);//libera memoria

}