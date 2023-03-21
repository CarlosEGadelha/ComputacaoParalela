#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>
//gcc -o main -fopenmp -lm main.c

void imprimeVetor(int *vetor, int n){
	printf("\nVETOR\n");
	for (int i =0; i<n; i++){
		printf(" %d ", vetor[i]);	
	}
	
}

int main(void) {
	int n = 8;
	int vetor[8] = {2,3,1,3,1,4,2,1};
	int nthreads, tid;
	int *vetor_b;
	int *vetor_p;
	time_t t;
	int n_b = 2*n;	
	
	vetor_b =(int *) malloc(n_b * sizeof (int));
	vetor_p =(int *) malloc(n_b * sizeof (int));

	for(int i=0; i<n_b; i++)
		vetor_b[i] = 0;

	
	for(int i=0; i<n_b; i++)
		vetor_p[i] = 0;
		
	imprimeVetor(vetor, n);
	
	#pragma omp parallel private(nthreads, tid)
	{
		tid = omp_get_thread_num();
    #pragma omp parallel for
		for(int i= 0; i <n; i++)
			vetor_b[n+i] = vetor[i];		
	}
	
	imprimeVetor(vetor_b, n_b);
	
	for(int j =(int)log2(n) - 1; j >= 0; j--){
		#pragma omp parallel for
		for(int i = 1 << j; i <= (1 << (j+1)) - 1; i++){
			vetor_b[i] = vetor_b[2*i] + vetor_b[2*i + 1];
		}
	}
	
	imprimeVetor(vetor_b, n_b);

	vetor_p[1]= vetor_b[1];
	// printf("\n%d\n",(int)log2(n));
	
	for(int j=1; j <= (int)log2(n); j++){
		#pragma omp parallel for
		for(int i = 1 << j; i <= (1 << (j+1)) - 1; i++){
			if(i%2 == 0)
				vetor_p[i] = vetor_p[i/2] - vetor_b[i+1];
			else
				vetor_p[i] = vetor_p[(i-1)/2];
		}
	}

	imprimeVetor(vetor_p, n_b);
	
  return 0;
}