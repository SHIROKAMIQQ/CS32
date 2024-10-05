#include "bqueue.h"
#include <stdlib.h>
#include <stdint.h>

typedef struct node node;
typedef struct deque deque;
void deque_push_rear(deque* d, int64_t val);
void deque_pop_rear(deque* d);
void deque_pop_front(deque* d);

typedef struct node {
    int64_t data;
    struct node* left;
    struct node* right;
} node;

typedef struct deque{
    struct node* front;
    struct node* rear;
} deque;

typedef struct queue{
    struct node* front;
    struct node* rear;
    struct deque* sorter;
} queue;

queue* queue_init(void) {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    deque* s = (deque*)malloc(sizeof(deque));
    s->front = NULL;
    s->rear = NULL;
    q->sorter = s;
    return q;
}

void deque_push_rear(deque* d, int64_t val){
    if(d->front == NULL && d->rear == NULL){
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

void enqueue(queue* d, int64_t val){
    if (d->front == NULL && d->rear == NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        d->front = newNode;
        d->rear = newNode;
        deque_push_rear(d->sorter, val);
        return;
    }
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = d->rear;
    newNode->right = NULL;
    d->rear->right = newNode;
    d->rear = d->rear->right;
    while (d->sorter->rear != NULL && val < d->sorter->rear->data) {
        deque_pop_rear(d->sorter);
    }
    deque_push_rear(d->sorter, val);

}
int64_t dequeue(queue *d){
    int64_t val = d->front->data;
    node* to_free = d->front;
    d->front = d->front->right;
    if (d->front != NULL) {
        d->front->left = NULL;
    } else {
        d->rear = NULL;
    }
    free(to_free);
    if (val == d->sorter->front->data) {
        deque_pop_front(d->sorter);
    }
    return val;
}
int64_t peek_front(queue *d){
    return d->front->data;
}
int64_t queue_min(queue *d){
    return d->sorter->front->data;
}
