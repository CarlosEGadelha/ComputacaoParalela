#include <stdio.h>
#include <stdlib.h>

void printVetor(int* A, int n){
  for(int i = 0; i <= n; i++)
    printf(" %d ", A[i]);
}

void swipe(int *A, int i, int j){
  int aux;
  aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

int* shellSort(int* A, int n){
  int h = n/2, chave, i, j;
  while(h > 0){
    for(j = h; j <= n; j++){
      chave = A[j];
      i = j;
      while(i >= h && A[i-h] > chave){
        A[i] = A[i-h];
        i = i-h;
      }
      A[i] = chave;
    }
  h = h/2;
  }
  return A;
}

int main(void){
  int A[8] = {6,2,5,1,8,9,0,3};
  int n = 8;

  printVetor(A, n);
  printf("\n");
  printVetor(shellSort(A,n), n);

}
