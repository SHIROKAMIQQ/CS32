#include "adj_list.h"
#include <stdlib.h>

adj_list* make_adj_list(int n, int e, edge* edges) {
    adj_list* ret = (adj_list*)malloc(sizeof(adj_list));
    list** a = (list**)malloc(n*sizeof(list*));
    for (int i = 0; i < n; i++) {a[i] = NULL;}

    for (int d = 0; d < e; d++) {
        list* newNode1 = (list*)malloc(sizeof(list));
        newNode1->node = edges[d].node2;
        newNode1->weight = edges[d].weight;
        newNode1->next = a[edges[d].node1];
        a[edges[d].node1] = newNode1;

        list* newNode2 = (list*)malloc(sizeof(list));
        newNode2->node = edges[d].node1;
        newNode2->weight = edges[d].weight;
        newNode2->next = a[edges[d].node2];
        a[edges[d].node2] = newNode2;
    }

    ret->n = n;
    ret->adj = a;

    return ret;
}