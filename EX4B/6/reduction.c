#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main (int argc, char **argv)
{
    const int server = 0;
    float value, value_sum;
    int num_procs, my_rank, mpi_error_code;

    mpi_error_code = MPI_Init(&argc, &argv);
    mpi_error_code = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    mpi_error_code = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    value_sum = 0.0;
    value = my_rank * num_procs;
    mpi_error_code =
        MPI_Reduce(&value, &value_sum, 1, MPI_FLOAT, MPI_SUM,
        server, MPI_COMM_WORLD);
    printf("%d: reduce  value_sum = %f\n", my_rank, value_sum);
    mpi_error_code =
        MPI_Allreduce(&value, &value_sum, 1, MPI_FLOAT, MPI_SUM,
        MPI_COMM_WORLD);
    printf("%d: all_reduce value_sum = %f\n", my_rank, value_sum);
    mpi_error_code = MPI_Finalize();
}