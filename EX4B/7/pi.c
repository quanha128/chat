#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

// Creates an array of random points. Each point has two values from 0 - 1
float **create_points(int num_elements) {
  float **points = (float **)malloc(sizeof(float*) * num_elements);
  for (int i = 0; i < num_elements; i++) {
    points[i] = (float*) malloc(sizeof(float) * 2);
    points[i][0] = (rand() / (float)RAND_MAX);
    points[i][1] = (rand() / (float)RAND_MAX);
  }
  return points;
}

int main (int argc, char** argv)
{
  int num_points_per_proc = 10000;

  const int server = 0;
  float value, value_sum;
  int num_procs, my_rank, mpi_error_code; 
  
  mpi_error_code = MPI_Init(&argc, &argv);
  mpi_error_code = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  mpi_error_code = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
	
  // Create a random array of points on all processes.
  srand(time(NULL)*my_rank);   // Seed the random number generator to get different results each time for each processor
  float **points = NULL;
  points = create_points(num_points_per_proc);

  // Count the points inside quarter-circle locally
  int local_sum = 0;
  int i;
  for (i = 0; i < num_points_per_proc; i++) {
    int z = points[i][0]*points[i][0] + points[i][1]*points[i][1];
    if(z < 1)
      local_sum++;
  }
  // Calculate PI value locally on each process
  printf("Local PI for process %d - %d, avg = %f\n", my_rank, local_sum, (float)local_sum / num_points_per_proc * 4);

  // Reduce all of the local sums into the global sum
  int global_sum;
  MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0,
             MPI_COMM_WORLD);

  // Print the result
  if (my_rank == server) {
    printf("Total sum = %d, avg = %f\n", global_sum, ((double) global_sum) / (num_points_per_proc * num_procs) * 4);
  }

  for (i = 0; i < num_points_per_proc; i++) {
    free(points[i]);
  }
  free(points);

  mpi_error_code = MPI_Barrier(MPI_COMM_WORLD);
  mpi_error_code = MPI_Finalize();
}