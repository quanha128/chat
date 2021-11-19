#include <stdio.h>

int main() {
    int x=7;
    int y=111;
    int t = (x>>3)&0x1;
    if (t==0x1) {
        printf("x: %d\n", x);
        y |= (1<<5) | (1<<6);
        printf("y: %d\n", y);
    }
    else{
        y &= ~((1<<5) | (1<<6));
        printf("x: %d\n", x);
        printf("y: %d\n", y);
    }
    return 0;
}

void stack_push(char c)
{
    pthread_mutex_lock(&mutex);
    if (count >= sizeof(buf)) {
        pthread_mutex_unlock(&mutex);
        return;
    }
    buf[count++] = c;
    pthread_mutex_unlock(&mutex);
}

char stack_pop(void)
{
    pthread_mutex_lock(&mutex);
    if (count <= 0) {
        pthread_mutex_unlock(&mutex);
        return '\0';
    }
    char c = buf[--count];
    pthread_mutex_unlock(&mutex);
    return c;
}