//AC
#include "rdeque.h"
#include <stdint.h>
#include <stdlib.h>


typedef struct node {
    int64_t data;
    struct node* left;
    struct node* right;
} node;

struct deque {
    struct node* leftmost;
    struct node* rightmost;
    uint32_t size;
    int rev;
};

deque* deque_init(void){
    deque* d = (deque*)malloc(sizeof(deque));
    d->leftmost = NULL;
    d->rightmost = NULL;
    d->size = 0;
    d->rev = 0;
    return d;
}

void deque_push_left(deque* d, int64_t val) {
    if (d->leftmost == NULL && d->rightmost == NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        d->leftmost = newNode;
        d->rightmost = newNode;
        d->size++;
        return;
    }
    if (d->rev == 1) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = val;
        newNode->left = d->rightmost;
        newNode->right = NULL;
        d->rightmost->right = newNode;
        d->rightmost = d->rightmost->right;
        d->size++;
    } else {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = d->leftmost;
        d->leftmost->left = newNode;
        d->leftmost = d->leftmost->left;
        d->size++;
    }
}
void deque_push_right(deque* d, int64_t val) {
    if (d->leftmost == NULL && d->rightmost == NULL) {
        deque_push_left(d, val);
        return;
    }
    if (d->rev == 1) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = d->leftmost;
        d->leftmost->left = newNode;
        d->leftmost = d->leftmost->left;
        d->size++;
    } else {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = val;
        newNode->left = d->rightmost;
        newNode->right = NULL;
        d->rightmost->right = newNode;
        d->rightmost = d->rightmost->right;
        d->size++;
    }
}
int64_t deque_peek_left(deque* d){
    return (d->rev == 1) ? d->rightmost->data : d->leftmost->data;
}
int64_t deque_peek_right(deque* d){
    return (d->rev == 1) ? d->leftmost->data : d->rightmost->data;
}
int64_t deque_pop_left(deque* d){
    if (d->rev == 1) {
        int64_t x = d->rightmost->data;
        node* to_free = d->rightmost;
        d->rightmost = d->rightmost->left;
        if (d->rightmost != NULL) {
            d->rightmost->right = NULL;
        }
        free(to_free);
        if (d->rightmost == NULL) {
            d->leftmost = NULL;
        }
        d->size--;
        return x;
    } else {
        int64_t x = d->leftmost->data;
        node* to_free = d->leftmost;
        d->leftmost = d->leftmost->right;
        if (d->leftmost != NULL) {
            d->leftmost->left = NULL;
        }
        free(to_free);
        if (d->leftmost == NULL) {
            d->rightmost = NULL;
        }
        d->size--;
        return x;
    }
}
int64_t deque_pop_right(deque* d){
    if (d->rev == 1) {
        int64_t x = d->leftmost->data;
        node* to_free = d->leftmost;
        d->leftmost = d->leftmost->right;
        if (d->leftmost != NULL) {
            d->leftmost->left = NULL;
        }
        free(to_free);
        if (d->leftmost == NULL) {
            d->rightmost = NULL;
        }
        d->size--;
        return x;
    } else {
        int64_t x = d->rightmost->data;
        node* to_free = d->rightmost;
        d->rightmost = d->rightmost->left;
        if (d->rightmost != NULL) {
            d->rightmost->right = NULL;
        }
        free(to_free);
        if (d->rightmost == NULL) {
            d->leftmost = NULL;
        }
        d->size--;
        return x; 
    }
}
bool deque_empty(deque* d){
    return (d->size == 0)? true : false;
}
uint32_t deque_size(deque* d){
    return d->size;
}
void deque_reverse(deque* d){
    d->rev = (d->rev + 1)%2;
}