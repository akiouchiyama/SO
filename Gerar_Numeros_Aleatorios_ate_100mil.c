#include <stdio.h>
#include <stdlib.h>



int main(void)
{
  FILE *arq;
  arq=fopen("Teste.in","w");//cria o arquivo a ser escrito
  int ynum;
  long int num;
  printf("Digite quantos numeros o arquivo deve ter:\n\n");
  scanf("%d",&ynum);

  if(ynum<0){
      printf("Digite oarquivo deve ter:\n\n");
      scanf("%d",&ynum);
  }
      arq=fopen("Teste.in","w");//cria o arquivo a ser escrito
  for (int i=0; i < ynum; i++)
  {
    /* gerando valores aleatórios entre zero e 100000 */
    fprintf(arq,"%d ", rand() % 100000);
  }
  fclose(arq);
  return 0;
}