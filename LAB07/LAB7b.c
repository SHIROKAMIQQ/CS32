#include "level_order.h"
#include <stdlib.h>

typedef struct queue_node {
    tree_node* t;
    struct queue_node* left;
    struct queue_node* right;
} queue_node;

typedef struct queue {
    struct queue_node* front;
    struct queue_node* rear;
} queue;

void enqueue(queue* q, tree_node* t);
void enqueue(queue* q, tree_node* t) {
    queue_node* newNode = (queue_node*)malloc(sizeof(queue_node));
    newNode->t = t;
    newNode->left = NULL;
    newNode->right = NULL;
    if (q->front == NULL && q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        newNode->left = q->rear;
        q->rear->right = newNode;
        q->rear = q->rear->right;
    }
}

tree_node* dequeue(queue* q);
tree_node* dequeue(queue* q) {
    queue_node* to_free = q->front;
    tree_node* to_pop = q->front->t;
    q->front = q->front->right;
    if (q->front != NULL) {
        q->front->left = NULL;
    } else {
        q->rear = NULL;
    }
    free(to_free);
    return to_pop;
}

void levelorder(tree_node *root){
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    enqueue(q, root);

    while (q->front != NULL && q->rear != NULL) {
        tree_node* p = dequeue(q);
        visit(p);
        ll_node* curr = p->children;
        while (curr != NULL) {
            enqueue(q, curr->node);
            curr = curr->next;
        }
    }

}
