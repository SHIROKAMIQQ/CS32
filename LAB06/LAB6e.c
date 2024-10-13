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

int64_t ph_pop_max(podium_heap *h){
    int64_t ret = ph_peek_max(h);
    da_set(h->vals, 0, da_pop(h->vals));
    h->size--;
    idx_t i = 0;
    idx_t leftson = 2*i + 1;
    idx_t rightson = 2*i + 2;
    while (leftson >= 0 && leftson <= da_size(h->vals)) {
        if (rightson >= 0 && rightson <= da_size(h->vals)) {
            if (da_get(h->vals, leftson) > da_get(h->vals, rightson)) {
                if (da_get(h->vals, i) < da_get(h->vals, leftson)) {
                    int64_t temp = da_get(h->vals, i);
                    da_set(h->vals, i, da_get(h->vals, leftson));
                    da_set(h->vals, leftson, temp);
                    i = leftson;
                    leftson = 2*i + 1;
                    rightson = 2*i + 2;
                } else {
                    break;
                }
            } else {
                if (da_get(h->vals, i) < da_get(h->vals, rightson)) {
                    int64_t temp = da_get(h->vals, i);
                    da_set(h->vals, i, da_get(h->vals, rightson));
                    da_set(h->vals, rightson, temp);
                    i = rightson;
                    leftson = 2*i + 1;
                    rightson = 2*i + 2;
                } else {
                    break;
                }
            }
        } else {
            if (da_get(h->vals, i) < da_get(h->vals, leftson)) {
                int64_t temp = da_get(h->vals, i);
                da_set(h->vals, i, da_get(h->vals, leftson));
                da_set(h->vals, leftson, temp);
                i = leftson;
                leftson = 2*i + 1;
                rightson = 2*i + 2;
            } else {
                break;
            } 
        }
    }
    return ret;
}
int64_t ph_peek_2nd_max(podium_heap *h);
int64_t ph_pop_2nd_max(podium_heap *h);
int64_t ph_peek_3rd_max(podium_heap *h);
int64_t ph_pop_3rd_max(podium_heap *h);
int32_t ph_size(podium_heap *h) {
    return h->size;
}

