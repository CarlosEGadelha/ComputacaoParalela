#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *vetor, int n){
  printf("\nVETOR\n");
  for(int i=0; i<n; i++)
    printf(" %d ", vetor[i]);
}

int buscaBinaria(int num, int *vetor, int i, int f){
  int inicio = i; 
  int fim = f;
  int meio;

  while(inicio<fim){
    meio = (inicio+fim)/2;
    
    if(num<vetor[meio])
      fim = meio-1;
    else if(num>vetor[meio])
      inicio = meio+1;
  }

  if(num<vetor[meio])
    return meio;
  else if(num>vetor[meio])
    return (meio+1);
}

int main(void){
  int n=8;
  int A[4]={13,14,17,19};
  int B[4]={11,15,16,20};
  int posicaoA[4], posicaoB[4], C[8];

  #pragma omp parallel for
  for(int i=0; i<(n/2); i++){
    posicaoA[i] = buscaBinaria(B[i], A, 0, (n/2)-1);
    posicaoB[i] = buscaBinaria(A[i], B, 0, (n/2)-1);
    C[posicaoA[i]+i] = B[i];
    C[posicaoB[i]+i] = A[i];
  }

  imprimeVetor(posicaoA, 4);
  imprimeVetor(posicaoB, 4);
  imprimeVetor(C, 7);
}
