#include "onions.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

bool traversable(grid* g, int i, int j, int64_t x, bool** onion);
int traverse(grid* g, int i, int j, int64_t x, bool** onion);

bool traversable(grid* g, int i, int j, int64_t x, bool** onion) {
    if (
        ((0 <= i && i < (g->r)) && (0 <= j && j < (g->c))) &&
        ((*onion)[(i*(g->c))+j] == true) &&
        (x >= ((g->h)[i][j])) 
    ){
        return true;
    } else {
        return false;
    }
}

int traverse(grid* g, int i, int j, int64_t x, bool** onion){
    int ret = 0;
    if (traversable(g, i, j, x, onion) == true){
        (*onion)[(i*(g->c))+j] = false;
        ret++;
        ret += traverse(g, i+1, j, x, onion);
        ret += traverse(g, i-1, j, x, onion);
        ret += traverse(g, i, j+1, x, onion);
        ret += traverse(g, i, j-1, x, onion);
    }
    return ret;
}

void onions(grid *g, int q, query *qs){
    bool* onion = (bool*)malloc((g->r)*(g->c)*sizeof(bool));
    for (int i = 0; i < (g->r)*(g->c); i++) {onion[i] = true;}
    for (int i = 0; i < q; i++) {
        query que = qs[i];
        int i1 = que.i1; 
        int j1 = que.j1;
        int i2 = que.i2; 
        int j2 = que.j2;
        int64_t x = que.x;
        int ans = 0;
        ans += traverse(g, i1, j1, x, &onion);
        ans += traverse(g, i2, j2, x, &onion);
        (qs[i]).ans = ans;
        for (int i = 0; i < (g->r)*(g->c); i++){onion[i]=true;}
    }
    free(onion);
}