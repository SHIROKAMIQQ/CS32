#include "downward_path.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void visit(int r, int c) {
    printf("VISITED: (%d, %d)\n", r, c);
}

int main () {

    printf("TEST CASE 1:\n");
    uint64_t h1r1[5] = {7,8,7,7,7};
    uint64_t h1r2[5] = {7,8,7,8,7};
    uint64_t h1r3[5] = {7,8,7,8,7};
    uint64_t h1r4[5] = {7,8,7,8,7};
    uint64_t h1r5[5] = {7,7,7,8,7};
    uint64_t* h1[5] = {h1r1, h1r2, h1r3, h1r4, h1r5};
    find_downward_path(5,5,h1) ? printf("TRUE\n") : printf("FALSE\n");    
    printf("\n");

    printf("TEST CASE 2:\n");
    uint64_t h2r1[5] = {10,8,7,5,1};
    uint64_t h2r2[5] = {10,8,7,5,10};
    uint64_t h2r3[5] = {5,8,7,5,10};
    uint64_t h2r4[5] = {4,4,4,4,4};
    uint64_t h2r5[5] = {10,10,10,10,1};
    uint64_t* h2[5] = {h2r1, h2r2, h2r3, h2r4, h2r5};
    find_downward_path(5,5,h2) ? printf("TRUE\n") : printf("FALSE\n");
    printf("\n");

    printf("TEST CASE 3:\n");
    uint64_t h3r1[5] = {10,8,7,5,1};
    uint64_t h3r2[5] = {10,8,7,5,10};
    uint64_t h3r3[5] = {5,8,7,5,10};
    uint64_t h3r4[5] = {4,4,4,11,11};
    uint64_t h3r5[5] = {10,10,10,11,1};
    uint64_t* h3[5] = {h3r1, h3r2, h3r3, h3r4, h3r5};
    find_downward_path(5,5,h3) ? printf("TRUE\n") : printf("FALSE\n");
    printf("\n");

    printf("TEST CASE 4: \n");
    uint64_t h4r1[1] = {10};
    uint64_t* h4[1] = {h4r1};
    find_downward_path(1,1,h4) ? printf("TRUE\n") : printf("FALSE\n");
    printf("\n");
    
    printf("TEST FINISHED");
}