#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

#define PHILOSOPHERS 5
#define DAYS 10000

static const char* names[] = {
    "Enryo", "Socrates", "Platon", "Aristoteles", "Kant"
};

int fork_status[] = {0,0,0,0,0};

pthread_t philosophers[PHILOSOPHERS];
pthread_mutex_t fork_mutex;
pthread_cond_t fork_avail;

static void eat(int phil, int fork1, int fork2)
{
    printf("%s: \"Yummy!\"\n", names[phil]);
}

int fork_stat(int fork_status[]) {
    int res=0;
    for (int i=0; i<5; i++) {
        if (fork_status[i]==1) res++;
    }
    return res;
}

void* philosopher_thread(void* arg)
{
    int phil = (int)(intptr_t)arg;
    unsigned int r = (phil << 16) + time(NULL);
    int left = phil;
    int right = (phil+1) % PHILOSOPHERS;
    int i;

    usleep(rand_r(&r) % 100);

    for (i = 0; i < DAYS; i++) {
        /* Think for a while */
        usleep(rand_r(&r) % 100);
        
        /* Staring to eat */
        pthread_mutex_lock(&fork_mutex);
        while (fork_stat(fork_status) >= 4) {
            pthread_cond_wait(&fork_avail, &fork_mutex);
        }
        while (fork_status[left]==1) {
            pthread_cond_wait(&fork_avail, &fork_mutex);
        }
        fork_status[left] = 1;
        printf("%s picked up the left fork\n", names[phil]);
        
        while (fork_status[right] == 1) {
            pthread_cond_wait(&fork_avail, &fork_mutex);
        }
        fork_status[right] = 1;
        printf("%s picked up the right fork\n", names[phil]);
        pthread_mutex_unlock(&fork_mutex);

        eat(phil, left, right);

        pthread_mutex_lock(&fork_mutex);
        fork_status[left] = 0;
        pthread_cond_broadcast(&fork_avail);
        printf("%s returned the right fork\n", names[phil]);
        fork_status[right] = 0;
        pthread_cond_broadcast(&fork_avail);
        printf("%s returned the left fork\n", names[phil]);
        pthread_mutex_unlock(&fork_mutex);

    }

    return NULL;
}


int main()
{
    int er, i;
    void* ret;

    er = pthread_mutex_init(&fork_mutex, NULL);
    if (er != 0) goto error;

    for (i = 0; i < PHILOSOPHERS; i++) {
        er = pthread_create(&philosophers[i], NULL, philosopher_thread, (void*)(intptr_t)i);
        if (er != 0) goto error;
    }
    for (i = 0; i < PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], &ret);
    }
    printf("finished\n");
    return 0;

 error:
    fprintf(stderr, "ERROR\n");
    return -1;
}