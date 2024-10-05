#include "circ_costs.h"

#include <stdlib.h>
#include <stdint.h>

typedef struct node node;
typedef struct deque deque;
deque* deque_init(void);
void deque_push_rear(deque* d, int64_t val);
void deque_pop_rear(deque* d);
void deque_pop_front(deque* d);
void deque_free(deque* d);
int64_t C(int n, int64_t* s, int k);

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
int64_t C(int n, int64_t* s, int k){
    if (n == 1) {
        return s[0];
    }
    if (k == n) {
        int64_t max = 0;
        for (int i = 0; i < n; i++) {
            max = (s[i] > max) ? s[i] : max;
        }
        return max*((int64_t)n);
    }
    deque* d = deque_init();
    int64_t max_sum = 0;

    int p = 0;
    for (int i = 0; i < n; i++) {
        while (p != ((i+k)%n)) {
            while (d->rear != NULL && s[d->rear->data] < s[p]){
                deque_pop_rear(d);
            }
            deque_push_rear(d, p);
            p = (p+1)%n;
        }
        max_sum += s[d->front->data];
        if (d->front->data == i) {
            deque_pop_front(d);
        }
    }

    return max_sum;
}

int circ_costs(int n, int64_t* s, int64_t v, int64_t e){
    int ret = 0;
    
    return ret;
}