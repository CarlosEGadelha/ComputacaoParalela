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

int* bubbleSort(int* A, int n){
  for(int i = 0; i < (n-1); i++){
    for(int j = 0; j < (n-1); j++){
      if(A[j] > A[j+1])
        swipe(A, j, j+1);
    }
  }

  return A;
}

int main(void){
  int A[8] = {6,2,5,1,8,9,0,3};
  int n = 8;

  printVetor(A, n);
  printf("\n");
  printVetor(bubbleSort(A,n), n);

}
