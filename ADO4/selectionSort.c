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

int* selectionSort(int* A, int n){
  int min;
  for(int i = 0; i < n-1; i++){
    min = i;
    for(int j = i+1; j < n; j++){
      if(A[j] < A[min])
        min = j;
    }
    swipe(A, i, min);
  }
  return A;
}

int main(void){
  int A[8] = {6,2,5,1,8,9,0,3};
  int n = 8;

  printVetor(A, n);
  printf("\n");
  printVetor(selectionSort(A,n), n);

}
