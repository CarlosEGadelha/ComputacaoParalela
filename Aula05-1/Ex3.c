#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>
//gcc -o main -fopenmp -lm main.c

void imprimeVetor(int *vetor, int n){
	printf("\nPESO\n");
	for (int i =0; i<n; i++)
		printf(" %d ", vetor[i]);	
	
}

int main(void){
	int n =5;
	int F[5] = {5,10,1,11,6};
	int pai[5] = {-1,0,1,2,3};
	// int peso[5] = {1,3,2,1,4};
	int peso[5] = {4,1,2,3,1};
	int soma[5];
	int p[5];
	int tid;

	// #pragma omp parallel private(tid)
	// {
		
	// }

	#pragma omp parallel for
	for(int i= 0; i <= (n-1); i++){
		p[i] = pai[i];
		soma[i] = peso[i];
	}

	#pragma omp parallel for
	for(int j= 0; j <= (n-1); j++){
		while(p[j] != -1){
			soma[j] += soma[p[j]];
			p[j] = p[p[j]];
		}
	}
	imprimeVetor(soma, n);
	
	return 0;
}