#include <stdio.h>
#include <mpi.h>

#define N 12

int main(int argc, char *argv[]){
      int id;
      int v1[N], v2[N], produtoE, produtoE_parcial;
      int P;
      int tag = 999;

      for(int i=0; i<N; i++)
        v1[i] = 2;

      for(int i=0; i<N; i++)
        v2[i] = 2;

      MPI_Init(&argc, &argv);
      MPI_Comm_rank(MPI_COMM_WORLD, &id);      
      MPI_Comm_size(MPI_COMM_WORLD, &P);

      MPI_Status status;
      int r = N/P;
      produtoE_parcial = 0;
      
      for(int i=id*r; i<=((id+1)*r)-1; i++){
        produtoE_parcial += (v1[i]*v2[i]);  
      }

      if(id==0){
        produtoE = 0;
      }
      else{
        MPI_Recv(&produtoE, 1, MPI_INT, id-1, tag, MPI_COMM_WORLD, &status);
      } 

      produtoE += produtoE_parcial;

      MPI_Send(&produtoE, 1, MPI_INT, (id+1)%P, tag, MPI_COMM_WORLD);


      if(id==0){
        MPI_Recv(&produtoE, 1, MPI_INT, P-1, tag, MPI_COMM_WORLD, &status);
        printf("\nPRODUTO ESCALAR TOTAL: %d\n", produtoE);
      }

      MPI_Finalize();
      return 0;
}
