#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char* argv[])
{ /* main */
    const int   maximum_message_length = 100;
    const int   server_rank = 0;
    char        message[maximum_message_length+1];
    MPI_Status  status;         // info about receiving status
    int         my_rank;        // this process id
    int         num_procs;      // number of processes in run
    int         source;         // process id to receive from
    int         destination;    // process id to send to
    int         tag = 0;        // message id
    int         mpi_error_code; // error code for mpi calls

    /* work goes here */

    mpi_error_code = MPI_Init(&argc, &argv);
    mpi_error_code = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    mpi_error_code = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    if (my_rank != server_rank) {
        sprintf(message, "Greeting from process #%d!", my_rank);
        destination = server_rank;
        mpi_error_code = MPI_Send(message, strlen(message)+1,
                MPI_CHAR, destination, tag, MPI_COMM_WORLD);
    } else {
        for (source = 0; source < num_procs; source++) {
            if (source != server_rank) {
                mpi_error_code = MPI_Recv(message, maximum_message_length+1,
                        MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
                fprintf(stderr, "%s\n", message);
            }
        }
    }
    mpi_error_code = MPI_Finalize();
} /* main */