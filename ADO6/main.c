#include <stdlib.h>
#include <stdio.h>

void imprimeVetor(int* vetor, int n){
  printf("\nVETOR\n");
  for(int i=0; i<n; i++)
    printf(" %d ", vetor[i]);
}

void computar_soma_prefixo(int a[], int b[], int i, int f){
  if(i<f){
    int m = (i+f)/2;

    #pragma omp task
    computar_soma_prefixo(a, b, i, m);

    #pragma omp task
    computar_soma_prefixo(a, b, m+1, f);

    #pragma omp taskwait
    
    #pragma omp for
    for(int k=0; k<(f-m); k++)
      b[(m+1)+k] += b[m];

  }
  else
    b[i] = a[i];
} 

int main(void){
  int n = 8;
  int a[8] = {4,8,1,5,2,7,3,6}; 
  int b[8];

  for(int i=0; i<n; i++)
    b[i] = 0;

  //imprimeVetor(a, n);
  //imprimeVetor(b, n);
  
  computar_soma_prefixo(a, b, 0, 7);
  
  imprimeVetor(a, n);
  imprimeVetor(b, n);
  
  return 0;
}
