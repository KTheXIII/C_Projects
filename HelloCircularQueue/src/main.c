#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define QUEUE_EMPTY INT_MIN

// Queue data structure with array
typedef struct {
    int32_t *values;
    int32_t head, tail, num_entries, size;
} queue;

void init_queue(queue *q, int32_t max_size) {
    q->size = max_size;
    q->values = malloc(sizeof(int32_t) * q->size);
    q->num_entries = 0;  // Empty
    q->head = 0;
    q->tail = 0;
}

bool queue_empty(queue *q) { return (q->num_entries == 0); }

bool queue_full(queue *q) { return (q->num_entries == q->size); }

void queue_destroy(queue *q) { free(q->values); }

bool enqueue(queue *q, int32_t value) {
    if (queue_full(q)) return false;

    q->values[q->tail] = value;
    q->num_entries++;
    q->tail = (q->tail + 1) % q->size;

    return true;
}

int32_t dequeue(queue *q) {
    int32_t result;
    if (queue_empty(q)) return QUEUE_EMPTY;

    result = q->values[q->head];
    q->head = (q->head + 1) % q->size;
    q->num_entries--;

    return result;
}

int main(int argc, char const *argv[]) {
    printf("Hello, Circular Queue!\n");

    queue q1;
    init_queue(&q1, 7);

    enqueue(&q1, 38);
    enqueue(&q1, 392);
    enqueue(&q1, 129);
    enqueue(&q1, 256);
    enqueue(&q1, 1024);
    enqueue(&q1, 932);
    enqueue(&q1, 2033);

    int t;
    while ((t = dequeue(&q1)) != QUEUE_EMPTY) {
        printf("t = %d\n", t);
    }

    queue_destroy(&q1);

    return 0;
}
