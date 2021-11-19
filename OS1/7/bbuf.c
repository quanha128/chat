#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct bbuf {
    int buf[10];
    int tail;
    int head;
    int count;
    pthread_mutex_t mtx;
    pthread_cond_t buf_empty;
    pthread_cond_t buf_full;
} bbuf;

void init_bb(bbuf* b) {
    pthread_mutex_init(&b->mtx, NULL);
    pthread_cond_init(&b->buf_empty,NULL);
    pthread_cond_init(&b->buf_full,NULL);
    b->head = 0;
    b->tail = 0;
    b->count = 0;
}

int bb_get (bbuf* b) {
    pthread_mutex_lock(&b->mtx);
    while (b->count<=0) {
        pthread_cond_wait(&b->buf_empty, &b->mtx);
    }
    int data = b->buf[b->head];
    b->head = (b->head+1)%10;
    b->count--;
    pthread_cond_broadcast(&b->buf_full);
    pthread_mutex_unlock(&b->mtx);
    return data;
}

void bb_put(bbuf* b, int c) {
    pthread_mutex_lock(&b->mtx);
    while (b->count>=10) {
        pthread_cond_wait(&b->buf_full, &b->mtx);
    }
    b->buf[b->tail] = c;
    printf("pushed: %d\n", b->buf[b->tail]);
    b->tail = (b->tail+1)%10;
    b->count++;
    pthread_cond_broadcast(&b->buf_empty);
    pthread_mutex_unlock(&b->mtx);
}

void* entry_push (void* arg) {
    for (int i=0; i<1000000; i++) {
        bb_put(arg, i);
    }
}

void* entry_pop (void* arg) {
    for (int i=0; i<1000000; i++) {
        printf("popped: %d\n", bb_get(arg));
    }
}

int main() {
    bbuf b;
    init_bb(&b);

    pthread_t tid1, tid2;
    void* ret;
    int er;

    er = pthread_create(&tid1, NULL, entry_push, &b);
    if (er != 0) goto error;
    er = pthread_create(&tid2, NULL, entry_pop, &b);
    if (er != 0) goto error;

    pthread_join(tid1, &ret);
    pthread_join(tid2, &ret);
    
    return 0;

error:
    fprintf(stderr, "ERROR\n");
    return -1;
}