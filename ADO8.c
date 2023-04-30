#include <stdio.h>
#include <mpi.h>

#define N 10

int main(int argc, char *argv[]){
      int id;
      int v[N], produto, produto_parcial;
      int P;
      int tag = 999;

      for(int i=0; i<N; i++)
        v[i] = 2;

      MPI_Init(&argc, &argv);
      MPI_Comm_rank(MPI_COMM_WORLD, &id);      
      MPI_Comm_size(MPI_COMM_WORLD, &P);

      MPI_Status status;
      int r = N/P;
      produto_parcial = 1;
      for(int i=id*r; i<=((id+1)*r)-1; i++){
        produto_parcial *= v[i];  
      }

      if(id==0){
        produto = 1;
      }
      else{
        MPI_Recv(&produto, 1, MPI_INT, id-1, tag, MPI_COMM_WORLD, &status);
      } 

      produto *= produto_parcial;

      MPI_Send(&produto, 1, MPI_INT, (id+1)%P, tag, MPI_COMM_WORLD);


      if(id==0){
        MPI_Recv(&produto, 1, MPI_INT, P-1, tag, MPI_COMM_WORLD, &status);
        printf("\nPRODUTO TOTAL: %d\n", produto);
      }

      MPI_Finalize();
      return 0;
}
