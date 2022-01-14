#include <stdio.h>
#include <omp.h>

#define MAX_THREADS 4

int main() {
  static long num_steps = 100000000;
  int i, j;
  double pi, total_sum = 0.0;
  double start_time, run_time;

  double dx = 1.0/(double) num_steps;
  
  for(j=1; j<=MAX_THREADS; j++) {
    start_time = omp_get_wtime(); 
    omp_set_num_threads(MAX_THREADS);

    total_sum = 0.0;
    #pragma omp parallel private(i)
    {
      int id = omp_get_thread_num();
      double x;
      double local_sum = 0;

      int numthreads = omp_get_num_threads();
      #pragma omp single
      printf("num_threads = %d\n", numthreads);

      for (i=id; i<num_steps; i+=numthreads) {
        x = (i+0.5) *dx;
        local_sum += 4.0/(1.0+x*x);
      }
      #pragma omp critical
      total_sum += local_sum;
    }

    pi = dx * total_sum;
    run_time = omp_get_wtime();

    printf("pi is %1.12lf in %f seconds %d threads\n", pi, run_time/1000, MAX_THREADS);
  }
}