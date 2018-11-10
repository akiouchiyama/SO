
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

/* ------------------------------------------------------------------
     DEFINIÇÕES PARA FUNÇÃO gettimeofday PARA VÊ TEMPO D EX DAS THREADS
   ------------------------------------------------------------------ */

//(fim*x+ms) - (inicio*x+ms) = tempo
#define GET_MS(ini, fim)  ((fim.tv_sec * 1000000 + fim.tv_usec) \
			- (ini.tv_sec * 1000000 + ini.tv_usec))
            struct timeval inicio, fim;

 /* ------------------------------------------------------------------
	     DECLARA TODAS AS VARIAVEIS GLOBAIS USADAS 
   ------------------------------------------------------------------ */           
    
int k=2; //Contador para saber quantos inteiros tem o arquivo de saída.
int j=1000; //Variavel para aumentar de 1000 em 1000 a memoria alocada.
int *num; //Memoria alocada dinamicamente.
int y=2; //Auxiliar para o vetor
/* ------------------------------------------------------------------
	     PROTOTIPO DE TODAS AS FUNÇÕES USADAS NO PROGRAMA 
   ------------------------------------------------------------------ */
 typedef struct{  // STRUCT PARA PASSAR OS VALORES PARA A THREAD.
        int *auxnum; //recebe INICIO VETOR
        int auxf; //recebe FINAL vetor
    }thread_arg, *ptr_thread_arg; 


void gerar_arquivo(int arqc, char* arqv[])    //FUNÇÃO GERA ARQUIVO .OUT
{        
    FILE *arq2; //Define arquivo que irá ser escrito        
    arq2=fopen(arqv[arqc-1],"w");//cria o arquivo a ser escrito
    int numero;
    for(int i=2; i<arqc-1;i++) //Laço para ver os arquivos de entrada
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

void *ordenacao (void *arg){ //algoritmo de ordenação - insertion short que será chamado pela thread

    ptr_thread_arg targ = (ptr_thread_arg)arg; //CARREGA A ESTRUTURA NA FUNÇÃO
    int i, j, x;
    for (i=y; i<=targ->auxf;i++){ //Y É O INICIO DO VETOR
    x = targ->auxnum[i];
    j=i-1;
    targ->auxnum[1] = x; 
    while (x < targ->auxnum[j]){
        targ->auxnum[j+1] = targ->auxnum[j];
        j--;
    }
    targ->auxnum[j+1] = x;
    }  
}

void escrita(int arqc, char* arqv[]){

    FILE *arq; //Define arquivo que irá ser escrito.
    arq=fopen(arqv[arqc-1],"w");//Abre o arquivo a ser lido.
    for(int i=2;i<k;i++){ //Escreve inteiro por inteiro no arquivo
      
      fprintf(arq,"%d ",num[i]);
    } 
    fclose(arq);//fecha arquivo após escreve tudo
}

void thread(int T){ //EXECUTA TODAS AS THREADS NA ORDENACAO


gettimeofday(&inicio, NULL); //INICIA A CONTAGEM DO TEMPO
    pthread_t thread[T]; //CRIA Números de Threads pedidas pelo usuário
    thread_arg arguments[T]; 
    for(int j=0; j<T;j++){        
        arguments[j].auxnum=num; //Recebe o vetor
        int a=j+1; //Variavel aux para aumentar o fim do vetor até o final da lista
        arguments[j].auxf=(((k-1)/T)*a)+ (k-1)%T; // Delimita o fim do vetor para cada Thread
        pthread_create(&thread[j],NULL, ordenacao,&(arguments[j]));
        pthread_join(thread[j],NULL); 
        y=arguments[j].auxf; //O FINAL do vetor passa a ser o começo a cada nova thread
        
    }

   
gettimeofday(&fim, NULL); //ENCERA A CONTAGEM DO TEMPO
printf("Tempo de execução: %ld ms\n\n", GET_MS(inicio, fim)); //MOSTRA O TEMPO EM MS.
}
/* -------------------------------------------------
			    INICIO DA FUNÇÃO MAIN 
   ------------------------------------------------- */
    int main(int arqc,char* arqv[])
{  
      int T = atoi (arqv[1]);//Numero de threads inseridas pelo Usuario
    
     if(T!=2 && T!=4 && T!=8 && T!=16){ //Se o número de threads diferente de 2,4,6,8 - SAI DO PROGRAMA
        printf("Numero de Threads Invalido\n");
        exit(1); //SAI DO PROGRAMA
    }

   gerar_arquivo(arqc, arqv); //Chama função geradora do arquivo de saida sem ordenação.
   vetoriza(arqc,arqv); //Função para ler o arquivo e salva os dados no vetor num

  
   thread(T);  //Carrega numero de Threads inseridas e começa a ordenada.
   escrita(arqc,arqv);
   free(num);//libera memoria7


        return 0;


}

