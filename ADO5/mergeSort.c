#include <stdio.h>
#include <stdlib.h>

void printVetor(int *A, int n){
  for(int i = 0; i <= n; i++)
    printf(" %d ", A[i]);
}

void swipe(int *A, int i, int j){
  int aux;
  aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

void mergeSort(int *A, int p, int r){
  if(p < r){
    int q = (p+r)/2;
    mergeSort(A, p, q);
    mergeSort(A, (q+1), r);
    merge(A, p, q, r);
  }
}

void merge(int *A, int p, int q, int r){
  int B[8], i, j, k;

  for(i = p; i <= q; i++)
    B[i] = A[i];
  for(j = q+1; j <= r; j++)
    B[r+q+1-j] = A[j];
  
  i = p;
  j = r;

  for(k = p; k <= r; k++){
    if(B[i] <= B[j]){
      A[k] = B[i];
      i = i+1;
    }
    else{
      A[k] = B[j];
      j = j-1;
    }
  }
}

int main(void){
  int A[8] = {6,2,5,1,8,9,0,3};
  int n = 8;

  printVetor(A, n);
  printf("\n");
  mergeSort(A, 0, n);
  printVetor(A, n);

}
