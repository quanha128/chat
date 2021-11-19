#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// pthread_mutex_t mtx;
// pthread_cond_t cond;

struct stack {
    int buf[1000000];
    int count;
    pthread_mutex_t mtx;
    pthread_cond_t cond;
};

void stack_init(struct stack* stk)
{
    pthread_mutex_init(&stk->mtx, NULL);
    pthread_cond_init(&stk->cond, NULL);
    stk->count = 0;
}

void stack_push(struct stack* stk, int val)
{
    pthread_mutex_lock(&stk->mtx);
    stk->buf[stk->count++] = val;
    printf("push: %d\n", val);
    pthread_cond_broadcast(&stk->cond);
    pthread_mutex_unlock(&stk->mtx);
}

int stack_pop(struct stack* stk)
{
    pthread_mutex_lock(&stk->mtx);
    while (stk->count <= 0) {
        pthread_cond_wait(&stk->cond, &stk->mtx);
    }
    int ret = stk->buf[--stk->count];
    printf("pop: %d\n", ret);
    pthread_mutex_unlock(&stk->mtx);
    return ret;
// fin:
//     pthread_mutex_unlock(&mtx);
//     fprintf(stderr, "ERROR: stack is empty\n");
//     abort();
}

void* thread_push(void* arg) {
    int i;
    for (i=0; i<1000000; i++) {
        stack_push(arg, i);
    }
    return NULL;
}

void* thread_pop(void* arg) {
    int i;
    for (i=0; i<1000000; i++) {
        stack_pop(arg);
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    struct stack stk;
    stack_init(&stk);

    pthread_t tid1, tid2;
    void* ret;
    int er;

    er = pthread_create(&tid1, NULL, thread_push, &stk);
    if (er != 0) goto error;
    er = pthread_create(&tid2, NULL, thread_pop, &stk);
    if (er != 0) goto error;
    
    pthread_join(tid1, &ret);
    pthread_join(tid2, &ret);
    
    return 0;

error:
    fprintf(stderr, "ERROR\n");
    return -1;
}
