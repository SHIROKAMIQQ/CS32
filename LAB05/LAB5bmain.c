#include "rdeque.h"

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
    deque* q1 = deque_init();
    deque_push_right(q1, 1);
    deque_reverse(q1);
    deque_push_left(q1, 2);
    deque_reverse(q1);
    VERIFY(deque_peek_left(q1) == 1);
    VERIFY(deque_peek_right(q1) == 2);
    VERIFY(deque_pop_left(q1) == 1);
    VERIFY(deque_peek_left(q1) == 2);
    VERIFY(deque_pop_left(q1) == 2);
    VERIFY(deque_empty(q1));
    printf("SUCCESS");
}