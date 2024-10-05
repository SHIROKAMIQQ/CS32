#include "circ_costs.h"

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

int64_t C(int n, int64_t* s, int k);

int main() {
    int64_t s1[4] = {3,1,4,1};
    int64_t ret1 = C(4, s1, 4);
    printf("%ld\n", ret1); 
}