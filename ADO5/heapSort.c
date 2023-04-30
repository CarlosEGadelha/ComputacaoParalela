#include <stdio.h>
#include <stdlib.h>

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

void desceHeap(int *A, int n, int i){
  int f;

  while((2*i) <= n){
    f = (2*i);
    if((f < n) && (A[f+1] > A[f]))
      f = f+1;
    if(A[i] < A[f]){
      swap(A, i, f);
      i = f;
    }
    else
      i = n+1;
  }
}

int maximoHeap(int *A, int n){
  int max = A[1];
  A[1] = A[n];

  desceHeap(A, n-1, 1);
 
  return max;
}

void constroiHeap(int *A, int n){
  for(int i = n/2; i >= 1; i--){
    desceHeap(A, n, i);
  }
}

int *heapSort(int *A, int n){
  constroiHeap(A, n);
  
  for(int i = n; i >= 2; i--){
    swap(A, 1, i);
    desceHeap(A, i-1, 1);
  }

  return A;
}

int main(void){
  int A[8] = {6,2,5,1,8,9,0,3};
  int n = 8;

  printVetor(A, n);
  printf("\n");
  printVetor(heapSort(A, n), n);

}
