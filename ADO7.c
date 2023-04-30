#include <stdio.h>
#include <mpi.h>

#define N 40

int main(int argc, char *argv[]){
      int id;
      int v[N], soma, soma_parcial;
      int P;
      int tag = 999;

      for(int i=0; i<N; i++)
        v[i] = 1;

      MPI_Init(&argc, &argv);
      MPI_Comm_rank(MPI_COMM_WORLD, &id);      
      MPI_Comm_size(MPI_COMM_WORLD, &P);

      MPI_Status status;
      int r = N/P;
      soma_parcial = 0;
      for(int i=id*r; i<=((id+1)*r)-1; i++){
        soma_parcial += v[i];  
      }

      if(id==0){
        soma = 0;
      }
      else{
        MPI_Recv(&soma, 1, MPI_INT, id-1, tag, MPI_COMM_WORLD, &status);
      } 

      soma += soma_parcial;

      MPI_Send(&soma, 1, MPI_INT, (id+1)%P, tag, MPI_COMM_WORLD);


      if(id==0){
        MPI_Recv(&soma, 1, MPI_INT, P-1, tag, MPI_COMM_WORLD, &status);
        printf("\nSOMA TOTAL: %d\n", soma);
      }

      MPI_Finalize();
      return 0;
}
