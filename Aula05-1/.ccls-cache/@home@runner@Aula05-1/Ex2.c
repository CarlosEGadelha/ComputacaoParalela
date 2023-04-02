#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>

//gcc -o main -fopenmp -lm main.c

struct Lista{
	int valor;
	struct Lista * prox;
};

void imprimeVetor(int *vetor, int n){
	printf("\nVETOR\n");
	for (int i =0; i<n; i++){
		printf(" %d ", vetor[i]);	
}

int main(void){
	int n =8;
	int p = prox;
	
	
  return 0;
}