#include "bqueue.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define VERIFY(b) do {\
    bool _b = (b);\
    fprintf(stderr, "verifying: %s\n", (#b));\
    if (!_b) {\
        fprintf(stderr, "verification failed!\n");\
        exit(1);\
    }\
} while (0)

int main() {
    queue* q1 = queue_init();
    enqueue(q1, 5);
    VERIFY(queue_min(q1) == 5);
    enqueue(q1, 6);
    VERIFY(queue_min(q1) == 5);
    VERIFY(dequeue(q1) == 5);
    VERIFY(queue_min(q1) == 6);
    VERIFY(dequeue(q1) == 6);

    printf("\n");
    queue* q2 = queue_init();
    enqueue(q2, 5);
    VERIFY(queue_min(q2) == 5);
    enqueue(q2, 1);
    VERIFY(queue_min(q2) == 1);
    VERIFY(peek_front(q2) == 5);
    VERIFY(dequeue(q2) == 5);
    VERIFY(peek_front(q2) == 1);
    VERIFY(queue_min(q2) == 1);
    enqueue(q2, 1);
    VERIFY(queue_min(q2) == 1);
    VERIFY(dequeue(q2) == 1);
    VERIFY(queue_min(q2) == 1);
    VERIFY(dequeue(q2) == 1);

    printf("ALL TESTS PASSED!");
}