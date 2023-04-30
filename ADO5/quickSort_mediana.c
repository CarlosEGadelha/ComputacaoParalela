#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVetor(int *A, int n){
  for(int i = 0; i <= n; i++)
    printf(" %d ", A[i]);
}

void swap(int *A, int i, int j){
  int aux;
  aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

int particiona_mediana(int *A, int p, int r){
  int mediana = p+(p-r)/2;
    
  return mediana;
}

int particiona(int *A, int p, int r){
  int indice_med = particiona_mediana(A, p, r);
  int x = A[indice_med], i = p-1, j;

  for(j = p; j <= r-1; j++){
    if(A[j] <= x){
      i++;
      swap(A, i, j);
    }
  }

  swap(A, i+1, r);
  return i+1;
}

int *quickSort(int *A, int p, int r){
  if(p < r){
    int q = particiona(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }

  return A;
}

int main(void){
  int A[8] = {6,2,5,1,8,9,0,3};
  int n = 8;

  printVetor(A, n);
  printf("\n");
  printVetor(quickSort(A, 0, n-1), n);

}
