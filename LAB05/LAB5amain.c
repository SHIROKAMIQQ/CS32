#include "deque.h"

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

deque deque_init() {
    deque d = {NULL, NULL, 0};
    return d;
}

void deque_push_left(deque *d, int64_t data) {
    if (d->size == 0) {
        deque_node* newNode = (deque_node*)malloc(sizeof(deque_node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        d->leftmost = newNode;
        d->rightmost = newNode;
        d->size++;
        return;
    }
    deque_node* newNode = (deque_node*)malloc(sizeof(deque_node));
    newNode->data = data;
    newNode->right = d->leftmost;
    newNode->left = NULL;
    d->leftmost->left = newNode;
    d->leftmost = d->leftmost->left; 
    d->size++;
}

void *oj_malloc(size_t size) {
    assert(size == sizeof(deque_node));
    return malloc(size);
}

void oj_free(void *ptr) {
    free(ptr);
}

int main() {
    deque q1 = deque_init();
    VERIFY(deque_empty(&q1));
    deque_push_right(&q1, 10);
    VERIFY(deque_pop_left(&q1) == 10);
    VERIFY(deque_empty(&q1));
    
    deque q2 = deque_init();
    VERIFY(deque_empty(&q2));
    deque_push_left(&q2, 1);
    deque_push_right(&q2, 2);
    deque_push_left(&q2, 3);
    VERIFY(deque_peek_left(&q2) == 3);
    VERIFY(deque_peek_right(&q2) == 2);
    VERIFY(deque_pop_right(&q2) == 2);
    VERIFY(deque_pop_right(&q2) == 1);
    VERIFY(deque_pop_left(&q2) == 3);
    //printf("%ld\n", deque_peek_left(&q2));
    //printf("%ld\n", deque_peek_right(&q2));
    VERIFY(deque_empty(&q2));
    deque_push_left(&q2, 1);
    VERIFY(deque_peek_left(&q2) == 1);
    VERIFY(deque_peek_right(&q2) == 1);
    VERIFY(deque_pop_left(&q2) == 1);
    VERIFY(deque_empty(&q2));
    VERIFY(deque_size(&q2) == 0);
    printf("test passed!\n");
}
