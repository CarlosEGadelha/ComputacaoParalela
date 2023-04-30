#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printVetor(int *A, int n){
  for(int i = 0; i <= n; i++)
    printf(" %d ", A[i]);
}

int aleatorio(int min, int max){
  time_t t;
  srand((unsigned) time(&t));

  return (rand()%(max-min)+min);
}

void swipe(int *A, int i, int j){
  int aux;
  aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

int particiona(int *A, int p, int r){
  int x = A[r], i = p-1, j;

  for(j = p; j <= r-1; j++){
    if(A[j] <= x){
      i++;
      swipe(A, i, j);
    }
  }

  swipe(A, i+1, r);
  return i+1;
}

int particiona_aleatorizado(int *A, int p, int r){
  int i = aleatorio(p, r);

  swipe(A, r, i);

  return particiona(A, p, r);
}

int *quickSort_aleatorizado(int *A, int p, int r){
  if(p < r){
    int q = particiona_aleatorizado(A, p, r);
    quickSort_aleatorizado(A, p, q-1);
    quickSort_aleatorizado(A, q+1, r);
  }

  return A;
}

int main(void){
  int A[8] = {6,2,5,1,8,9,0,3};
  int n = 8;

  printVetor(A, n);
  printf("\n");
  printVetor(quickSort_aleatorizado(A, 0, n-1), n);

}
