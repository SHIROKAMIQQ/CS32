#ifndef ADJ_LIST_H
#define ADJ_LIST_H

#include <stdint.h>

typedef struct list {
    int node;
    int64_t weight;
    struct list *next;
} list;

typedef struct adj_list {
    int n;
    list **adj;
} adj_list;

typedef struct edge {
    int node1;
    int node2;
    int64_t weight;
} edge;

adj_list *make_adj_list(int n, int e, edge *edges);

#endif
