#include <stdbool.h>
#include <pthread.h>

pthread_mutex_t time_mtx; /* already initialized */

int h; /* hour */
int m; /* minutes */

void nextmin(void)
{
    pthread_mutex_lock(&time_mtx);
    m++;
    if (m < 60) {
        pthread_mutex_unlock(&time_mtx);
        return;
    }
    m -= 60;
    h++;
    pthread_mutex_unlock(&time_mtx);
}