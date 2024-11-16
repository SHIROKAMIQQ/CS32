#include "stroll.h"
#include <stdlib.h>
#include <stdio.h>

void visit(int i) {
    printf("VISIT: %d\n", i);
}

int main() {
    printf("TEST CASE 1: \n");
    int n1 = 4;
    int r1 = 5;
    road* roads1 = (road*)malloc(r1*sizeof(road));
    int city1[5] = {0, 0, 2, 2, 3};
    int city2[5] = {2, 1, 1, 3, 1};
    for (int i = 0; i < r1; i++) {
        roads1[i].start = city1[i];
        roads1[i].end = city2[i];
    }
    find_leisurely_path(n1, r1, roads1);
    printf("\n");
}