#include <stdio.h>
#include <omp.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
  int numprocs, rank;
  int iam = 0, np = 1;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  np = omp_get_max_threads();

  #pragma omp parallel default (shared) private(iam)
  {
    iam = omp_get_thread_num();
    printf("Hello from %d/%d from process %d/%d.\n", iam, np, rank, numprocs);
  }

  MPI_Finalize();
}