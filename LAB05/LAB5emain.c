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

int64_t C(int n, int64_t** s, int k);
int main() {
    int64_t* s3 = (int64_t*)malloc(4*sizeof(int64_t));
    s3[0] = 3;
    s3[1] = 1;
    s3[2] = 4;
    s3[3] = 1;
    int64_t c3_1 = C(4, &s3, 1);
    int64_t c3_2 = C(4, &s3, 2);
    int64_t c3_3 = C(4, &s3, 3);
    int64_t c3_4 = C(4, &s3, 4);
    printf("%ld\n", c3_1);
    printf("%ld\n", c3_2);
    printf("%ld\n", c3_3);
    printf("%ld\n", c3_4);
    printf("\n");

    int64_t s1[14] = {2, 7, 1, 8, 2, 8, 2, 8, 4, 5, 9, 0, 4, 5};
    printf("CIRC COSTS: %ld\n\n", circ_costs(14, s1, 120, 4));
    int64_t s2[14] = {2, 7, 1, 8, 2, 8, 2, 8, 4, 5, 9, 0, 4, 5};
    printf("CIRC COSTS: %ld\n\n", circ_costs(14, s2, 120, 5));
    int64_t s4[2] = {1,2};
    printf("CIRC COSTS: %ld\n\n", circ_costs(2, s4, 3, 1));
    printf("CIRC COSTS: %ld\n\n", circ_costs(2, s4, 4, 1));
    printf("CIRC COSTS: %ld\n\n", circ_costs(2, s4, 5, 1));
    printf("CIRC COSTS: %ld\n\n", circ_costs(2, s4, 2, 1));
    printf("CIRC COSTS: %ld\n\n", circ_costs(2, s4, 2, 10));
}