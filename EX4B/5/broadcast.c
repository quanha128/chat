#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char* argv[])
{ /* main */
    const int server = 0;
    const int source = server;
    int* array = (int*)NULL;
    int length;
    int num_procs, my_rank, mpi_error_code;

    mpi_error_code = MPI_Init(&argc, &argv);
    mpi_error_code = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    mpi_error_code = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    if (my_rank == server) {
        length = num_procs;
        array = (int*)malloc(sizeof(int)*length);
        for (int i=0; i<length; i++) {
            array[i] = i*i;
        } //set value of array
    }

    if (num_procs > 1) {
        // broadcast length
        mpi_error_code = MPI_Bcast(&length, 1, MPI_INTEGER, source, MPI_COMM_WORLD);

        if (my_rank != server) {
            array = (int*)malloc(sizeof(int)*length);
        }
        // broadcast all values in array
        mpi_error_code = MPI_Bcast(array, length, MPI_INTEGER, source, MPI_COMM_WORLD);

        printf("%d: broadcast values = %d\n", my_rank, array[my_rank]);
    }
    mpi_error_code = MPI_Finalize();
}