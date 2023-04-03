#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *vetor, int n){
  printf("\nVETOR\n");
  for(int i=0; i<n; i++)
    printf(" %d ", vetor[i]);
}

int *map(int *vetor, int n){
  int *bits=(int*)malloc(n*sizeof(int));

  for(int i=0; i<n; i++){
    if(vetor[i]>10)
      bits[i]=1;
    else
      bits[i]=0;
  }

  return bits;
}

int *somaPrefixos(int *vetor, int n){
  int *bits_soma=(int*)malloc(n*sizeof(int));
  int soma=0;

  for(int i=0; i<n; i++){
    soma+=vetor[i];
    bits_soma[i]=soma;
  }

  return bits_soma;
}

int main(void){
  int n=10;
  int entrada[10]={17,4,6,8,11,5,13,19,0,24};
  int *bits= map(entrada, n);
  int *bits_soma= somaPrefixos(bits, n);
  int saida_tamanho=0;
  int *vetor_saida= (int*)malloc(saida_tamanho*sizeof(int));

  imprimeVetor(entrada,n);
  imprimeVetor(bits,n);
  imprimeVetor(bits_soma,n);
  
  #pragma omp palallel for
  for(int i=0; i<n; i++){
    if(bits[i] == 1){
      saida_tamanho++;
      vetor_saida=(int*)realloc(vetor_saida, saida_tamanho*sizeof(int));
      vetor_saida[bits_soma[i]-1]=entrada[i];
    }
  }
  
  imprimeVetor(vetor_saida, saida_tamanho);
}
