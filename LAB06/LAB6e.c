#include "podium_heap.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void ph_push(podium_heap *h, int64_t value){
    idx_t i = da_size(h->vals);
    idx_t parent = (i-1)/2;
    da_push(h->vals, value);
    h->size++;
    while ((parent >= 0 && parent <= da_size(h->vals)) &&
            value > da_get(h->vals, parent)){
        da_set(h->vals, i, da_get(h->vals, parent));
        da_set(h->vals, parent, value);
        i = parent;
        parent = (i-1)/2;
    }
}

int64_t ph_pop_max(podium_heap *h);
int64_t ph_peek_2nd_max(podium_heap *h);
int64_t ph_pop_2nd_max(podium_heap *h);
int64_t ph_peek_3rd_max(podium_heap *h);
int64_t ph_pop_3rd_max(podium_heap *h);
int32_t ph_size(podium_heap *h) {
    return h->size;
}

