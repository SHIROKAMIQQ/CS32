#include "paths.h"
#include <stdio.h>
#include <stdlib.h>

void visit(int city) {
    printf("VISITED: %d\n", city);
}

int main() {
    road* roads1 = (road*)malloc(8*sizeof(road));
    roads1[0].city1 = 1; roads1[0].city2 = 2;
    roads1[1].city1 = 2; roads1[1].city2 = 3;
    roads1[2].city1 = 2; roads1[2].city2 = 5;
    roads1[3].city1 = 3; roads1[3].city2 = 4;
    roads1[4].city1 = 4; roads1[4].city2 = 6;
    roads1[5].city1 = 6; roads1[5].city2 = 7;
    roads1[6].city1 = 6; roads1[6].city2 = 8;
    roads1[7].city1 = 5; roads1[7].city2 = 4;
    find_path(8, 8, roads1);
    printf("\n");

    road* roads2 = (road*)malloc(0*sizeof(road));
    find_path(1, 0, roads2);
    printf("\n");
}