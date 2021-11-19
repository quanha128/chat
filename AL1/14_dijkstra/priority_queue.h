/* priority_queue.h */

#define QUEUE_SIZE 128

typedef int (*Comparefn)(T a, T b);

typedef struct priority_queue {
    T array[QUEUE_SIZE];
    int size;
    Comparefn compare;
} priority_queue;

priority_queue* priority_queue_construct(Comparefn compare);
void priority_queue_free(priority_queue* queue);

void priority_queue_enqueue(priority_queue* queue, T value);
T priority_queue_dequeue(priority_queue* queue);
