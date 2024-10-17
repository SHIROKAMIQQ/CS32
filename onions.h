#ifndef ONIONS_H
#define ONIONS_H

#include <stdint.h>

typedef struct grid {
    int r, c;
    int64_t **h;
} grid;

typedef struct query {
    int i1, j1;
    int i2, j2;
    int64_t x;
    int ans;
} query;

void onions(grid *g, int q, query *qs);

#endif
