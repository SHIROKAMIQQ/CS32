#include "circ_costs.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct node node;
typedef struct deque deque;
deque* deque_init(void);
void deque_push_rear(deque* d, int64_t val);
void deque_pop_rear(deque* d);
void deque_pop_front(deque* d);
void deque_free(deque* d);
int64_t C(int n, int64_t** s, int k);
int binary_search(int n, int64_t** s, int64_t val, int search_for);

typedef struct node{
    int64_t data;
    struct node* left;
    struct node* right;
} node;
typedef struct deque{
    struct node* front;
    struct node* rear;
} deque;
deque* deque_init(void){
    deque* d = (deque*)malloc(sizeof(deque));
    d->front = NULL;
    d->rear = NULL;
    return d;
}
void deque_push_rear(deque* d, int64_t val){
    if (d->front == NULL && d->rear == NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        d->front = newNode;
        d->rear = newNode;
        return;
    }
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = d->rear;
    newNode->right = NULL;
    d->rear->right = newNode;
    d->rear = d->rear->right;
}
void deque_pop_rear(deque* d){
    node* to_free = d->rear;
    d->rear = d->rear->left;
    if (d->rear != NULL) {
        d->rear->right = NULL;
    } else {
        d->front = NULL;
    }
    free(to_free);
}
void deque_pop_front(deque* d){
    node* to_free = d->front;
    d->front = d->front->right;
    if (d->front != NULL) {
        d->front->left = NULL;
    } else {
        d->rear = NULL;
    }
    free(to_free);
}
void deque_free(deque* d){
    while (d->front != NULL) {
        node* to_free = d->front;
        d->front = d->front->right;
        free(to_free);
    }
}
int64_t C(int n, int64_t** s, int k){
    if (n == 1) {
        return (*s)[0];
    }
    if (k == n) {
        int64_t max = 0;
        for (int i = 0; i < n; i++) {
            max = ((*s)[i] > max) ? (*s)[i] : max;
        }
        return max*((int64_t)n);
    }
    deque* d = deque_init();
    int64_t max_sum = 0;

    int p = 0;
    for (int i = 0; i < n; i++) {
        while (p != ((i+k)%n)) {
            while (d->rear != NULL && (*s)[d->rear->data] < (*s)[p]){
                deque_pop_rear(d);
            }
            deque_push_rear(d, p);
            p = (p+1)%n;
        }
        max_sum += (*s)[d->front->data];
        if (d->front->data == i) {
            deque_pop_front(d);
        }
    }

    return max_sum;
}
int binary_search(int n, int64_t** s, int64_t val, int search_for) {
    int l = 1, r = n;
    while (r-l != 1) {
        int m = (l+r)/2;
        int64_t cm = C(n, s, m);
        if (cm == val) {
            return m;
        }
        if (cm < val) {
            l = m;
        } else {
            r = m;
        }
    }
    return (search_for == 0) ? r : l;
}
int circ_costs(int n, int64_t* s, int64_t v, int64_t e){
    int64_t min = v-e;
    int64_t max = v+e;
    int64_t sum1 = C(n, &s, 1);
    int64_t sumn = C(n, &s, n);

    if (sum1 > max || sumn < min) {
        return 0;
    }

    int min_i = 0;
    int max_i = 0;
    if (min <= sum1) {
        min_i = 1;
    } else {
        min_i = binary_search(n, &s, min, 0);
    }
    if (max >= sumn) {
        max_i = n;
    } else {
        max_i = binary_search(n, &s, max, 1);
    }

    printf("v: %ld, ", v);
    printf("e: %ld\n", e);
    printf("min: %ld, ", v-e);
    printf("max: %ld\n", v+e);
    for (int i = 1; i <= n; i++) {
        printf("When k=%d: %ld\n", i, C(n, &s, i));
    }
    printf("MAX_I = %d, MIN_I = %d\n", max_i, min_i);
    
    return max_i - min_i + 1;
}