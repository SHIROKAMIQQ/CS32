#include "onions.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

query _query(int i1, int j1, int i2, int j2, int64_t x) {
    query q;
    q.i1 = i1; q.j1 = j1;
    q.i2 = i2; q.j2 = j2;
    q.x = x;
    return q;
}

int main() {
    grid* grid1 = (grid*)malloc(sizeof(grid));
    grid1->r = 4;
    grid1->c = 5;
    /*int64_t h1[4][5] = {
        {3, 1, 4, 1, 5},
        {9, 2, 6, 5, 3},
        {5, 8, 9, 7, 9},
        {3, 2, 3, 8, 4}
    };*/
    int64_t** h1 = (int64_t**)malloc(4*sizeof(int64_t*));
    h1[0] = (int64_t*)malloc(5*sizeof(int64_t));
    h1[0][0] = 3;
    h1[0][1] = 1;
    h1[0][2] = 4;
    h1[0][3] = 1;
    h1[0][4] = 5;
    h1[1] = (int64_t*)malloc(5*sizeof(int64_t));
    h1[1][0] = 9;
    h1[1][1] = 2;
    h1[1][2] = 6;
    h1[1][3] = 5;
    h1[1][4] = 3;
    h1[2] = (int64_t*)malloc(5*sizeof(int64_t));
    h1[2][0] = 5;
    h1[2][1] = 8;
    h1[2][2] = 9;
    h1[2][3] = 7;
    h1[2][4] = 9;
    h1[3] = (int64_t*)malloc(5*sizeof(int64_t));
    h1[3][0] = 3;
    h1[3][1] = 2;
    h1[3][2] = 3;
    h1[3][3] = 8;
    h1[3][4] = 4;
    grid1->h = h1;
    int q1 = 9;
    query* qs1 = (query*)malloc(q1*sizeof(query));
    qs1[0] = _query(0, 1, 0, 1, 1);
    qs1[1] = _query(0, 1, 0, 1, 3);
    qs1[2] = _query(0, 1, 0, 1, 4);
    qs1[3] = _query(0, 1, 0, 1, 5);
    qs1[4] = _query(0, 1, 0, 3, 1);
    qs1[5] = _query(0, 1, 0, 3, 3);
    qs1[6] = _query(0, 1, 0, 3, 4);
    qs1[7] = _query(0, 1, 0, 3, 5);
    qs1[8] = _query(0, 1, 3, 0, 7);
    onions(grid1, q1, qs1);
    for (int i = 0; i < q1; i++) {
        printf("If (i1,j1) = (%d,%d), ", (qs1[i]).i1, (qs1[i]).j1);
        printf("(i2,j2) = (%d,%d), ", (qs1[i]).i2, (qs1[i]).j2);
        printf("and x = %ld ", (qs1[i]).x);
        printf("then they collect %d onions", (qs1[i]).ans);
        printf("\n");
    }
}