#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    const int server = 0;
    float value, value_sum, average;
    int num_procs, my_rank, mpi_error_code;

    mpi_error_code = MPI_Init(&argc, &argv);
    mpi_error_code = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    mpi_error_code = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    value_sum = 0.0;
    value = 1.0;
    for (int i=0; i<my_rank; i++) {
        value *= my_rank;
    }
    mpi_error_code =
        MPI_Reduce(&value, &value_sum, 1, MPI_FLOAT, MPI_SUM,
        server, MPI_COMM_WORLD);
    average = value_sum / num_procs;
    printf("%d: value_sum = %f  average = %f\n", my_rank, value_sum, average);
    mpi_error_code = MPI_Finalize();
}