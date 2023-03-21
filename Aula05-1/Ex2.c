#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>

//gcc -o main -fopenmp -lm main.c

void imprimeVetor(int *vetor, int n){
	printf("\nVETOR\n");
	for (int i =0; i<n; i++)
		printf(" %d ", vetor[i]);	
	}


int main(void){
	int n =8;
	int prox[8] = {NULL,5,0,6,7,3,2,1};
       	int p[n];	
	int nthreads, tid;
	int dist[n];

	for(int i=0; i<n; i++)
		p[i] = 0;

	for(int i=0; i<n; i++)
		dist[i] = 0;

	imprimeVetor(prox, n);
	//imprimeVetor(p, n);
	imprimeVetor(dist,n);

	#pragma omp parallel private(nthreads, tid)
	{
		tid = omp_get_thread_num();
		#pragma omp parallel for
		for(int i =0; i<n; i++){
			p[i] = prox[i];
			if(p[i] == NULL)
				dist[i] = 0;
			else
				dist[i] = 1;	
		}
	}
		
	printf("\nPROX\n");
	imprimeVetor(prox, n);
	printf("\nP\n");
	imprimeVetor(p, n);
	printf("\ndist\n");
	imprimeVetor(dist,n);	

	#pragma omp parallel private(nthreads, tid)
	{
		for(int j =1; j <= (int)log2(n); j++){
			#pragma omp parallel for
			for(int i=0; i<n; i++){
				if(p[i] != NULL){
					dist[i] = dist[i] + dist[p[i]];
					p[i] = p[p[i]];
				}	
			}
		}
	}
		
	printf("\nDISTANCIA: %d", &dist[0]);	
	
  return 0;
}
