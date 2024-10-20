#include "onions.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define E12 1000000000000

bool traversable(grid* g, int i, int j, int64_t x);
int traverse(grid* g, int i, int j, int64_t x);
void reset(grid* g, int i, int j);

bool traversable(grid* g, int i, int j, int64_t x) {
    if (
        ((0 <= i && i < (g->r)) && (0 <= j && j < (g->c))) &&
        (x >= ((g->h)[i][j])) 
    ){
        return true;
    } else {
        return false;
    }
}

int traverse(grid* g, int i, int j, int64_t x){
    int ret = 0;
    if (traversable(g, i, j, x) == true){
        ret++;
        (g->h)[i][j] += E12;
        ret += traverse(g, i+1, j, x);
        ret += traverse(g, i-1, j, x);
        ret += traverse(g, i, j+1, x);
        ret += traverse(g, i, j-1, x);
    }
    return ret;
}

void reset(grid* g, int i, int j) {
    if (
        ((0 <= i && i < (g->r)) && (0 <= j && j < (g->c))) &&
        (((g->h)[i][j]) >= E12) 
    ) {
        (g->h)[i][j] -= E12;
        reset(g, i+1, j);
        reset(g, i-1, j);
        reset(g, i, j+1);
        reset(g, i, j-1);
    } 
}

void onions(grid *g, int q, query *qs){
    for (int i = 0; i < q; i++) {
        query que = qs[i];
        int i1 = que.i1; 
        int j1 = que.j1;
        int i2 = que.i2; 
        int j2 = que.j2;
        int64_t x = que.x;
        int ans = 0;
        ans += traverse(g, i1, j1, x);
        ans += traverse(g, i2, j2, x);
        (qs[i]).ans = ans;
        reset(g, i1, j1);
        reset(g, i2, j2);
    }
}