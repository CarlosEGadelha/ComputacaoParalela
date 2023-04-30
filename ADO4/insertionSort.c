#include <stdio.h>
#include <stdlib.h>

void printVetor(int* A, int n){
  for(int i = 0; i <= n; i++)
    printf(" %d ", A[i]);
}

int* insertionSort(int* A, int n){
  int i, j, chave;
  
  for(i = 1; i <= n; i++){
    chave = A[i];
    j = i-1;
    while (j >= 0 && A[j] > chave) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = chave;
  } 
  return A;
}

int main(void){
  int A[8] = {6,2,5,1,8,9,0,3};
  int n = 8;

  printVetor(A, n);
  printf("\n");
  printVetor(insertionSort(A,n), n);

}
