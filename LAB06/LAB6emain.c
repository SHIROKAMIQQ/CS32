#include "podium_heap.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct dynamic_array{
    int64_t* arr;
    idx_t size;
} dynamic_array;
dynamic_array *da_init(void){
    dynamic_array* da = (dynamic_array*)malloc(sizeof(dynamic_array));
    int64_t* a = (int64_t*)malloc(100*sizeof(int64_t));
    da->arr = a;
    da->size = 0;
    return da;
}
void da_set(dynamic_array *a, idx_t i, int64_t val){
    (a->arr)[i] = val;
}
int64_t da_get(dynamic_array *a, idx_t i){
    return (a->arr)[i];
}
void da_push(dynamic_array *a, int64_t val){
    (a->arr)[(a->size)++] = val;
}
int64_t da_pop(dynamic_array *a){
    return (a->arr)[--(a->size)];
}
int32_t da_size(dynamic_array *a){
    return (a->size);
}
bool da_empty(dynamic_array *a){
    return (a->size == 0) ? true : false;
} 

podium_heap* ph_init() {
    podium_heap *h = (podium_heap*)malloc(sizeof(podium_heap));
    h->vals = da_init();
    h->size = 0;
    assert(ph_empty(h));
    return h;
}

int64_t ph_peek_max(podium_heap* h) {
    assert(!ph_empty(h));
    return da_get(h->vals, 0);
}

bool ph_empty(podium_heap* h) {
    return ph_size(h) == 0;
}

void print_list(int64_t* arr, idx_t length) {
    if (length == 0) {printf("NULL");}
    else {
        for (idx_t i = 0; i < length; i++) {
            printf("%ld ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    podium_heap* ph1 = ph_init();
    printf("EMPTY: %d\n", ph_empty(ph1));
    ph_push(ph1, 50);
    printf("PUSHED 50: "); print_list(ph1->vals->arr, ph_size(ph1));
    printf("SIZE: %d\n", ph_size(ph1));
    ph_push(ph1, 60);
    printf("PUSHED 60: "); print_list(ph1->vals->arr, ph_size(ph1));
    printf("SIZE: %d\n", ph_size(ph1));
    ph_push(ph1, 1);
    printf("PUSHED 1: "); print_list(ph1->vals->arr, ph_size(ph1));
    printf("SIZE: %d\n", ph_size(ph1));
    printf("POP %ld: ", ph_pop_max(ph1)); print_list(ph1->vals->arr, ph_size(ph1));
    printf("SIZE: %d\n", ph_size(ph1));
    ph_push(ph1, 70);
    printf("PUSHED 70: "); print_list(ph1->vals->arr, ph_size(ph1));
    ph_push(ph1, 35);
    printf("PUSHED 35: "); print_list(ph1->vals->arr, ph_size(ph1));
    ph_push(ph1, 40);
    printf("PUSHED 40: "); print_list(ph1->vals->arr, ph_size(ph1));
    ph_push(ph1, 34);
    printf("PUSHED 34: "); print_list(ph1->vals->arr, ph_size(ph1));
    ph_push(ph1, 16);
    printf("PUSHED 16: "); print_list(ph1->vals->arr, ph_size(ph1));

    printf("POP %ld: ", ph_pop_max(ph1)); print_list(ph1->vals->arr, ph_size(ph1));
    printf("POP %ld: ", ph_pop_max(ph1)); print_list(ph1->vals->arr, ph_size(ph1));
}
