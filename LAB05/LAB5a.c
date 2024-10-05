#include "deque.h"
#include <stdlib.h> 
deque deque_init(void);
void deque_push_left(deque *d, int64_t data);

void deque_push_right(deque *d, int64_t data) {
    if (d->size == 0) {
        deque_push_left(d, data);
        return;
    }
    deque_node* newNode = oj_malloc(sizeof(deque_node));
    newNode->data = data;
    newNode->left = d->rightmost;
    newNode->right = NULL;
    d->rightmost->right = newNode;
    d->rightmost = d->rightmost->right; 
    d->size++;
}
int64_t deque_peek_left(deque *d){
    return d->leftmost->data;
}
int64_t deque_peek_right(deque *d){
    return d->rightmost->data;
}
int64_t deque_pop_left(deque *d){
    int64_t x = d->leftmost->data;
    deque_node* to_free = d->leftmost;
    d->leftmost = d->leftmost->right;
    if (d->leftmost != NULL) {
        d->leftmost->left = NULL;
    } else {
        d->rightmost = NULL;
    }
    oj_free(to_free);
    d->size--;
    return x;
}
int64_t deque_pop_right(deque *d) {
    int64_t x = d->rightmost->data;
    deque_node* to_free = d->rightmost;
    d->rightmost = d->rightmost->left;
    if (d->rightmost != NULL) {
        d->rightmost->right = NULL;
    } else {
        d->leftmost = NULL;
    }
    oj_free(to_free);
    d->size--;
    return x; 
}
bool deque_empty(deque *d){
    return (d->size == 0) ? true : false;
}
uint32_t deque_size(deque *d){
    return d->size;
}