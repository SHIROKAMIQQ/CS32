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

void helper(queue* parent_queue, queue* child_queue) {
    while (parent_queue->front != NULL && parent_queue->rear != NULL) {
        tree_node* parent = dequeue(parent_queue);
        visit(parent);
        ll_node* current_child = parent->children;
        while (current_child != NULL) {
            enqueue(child_queue, current_child->node);
            current_child = current_child->next;
        }
    }
    helper(child_queue, parent_queue);
}

void levelorder(tree_node *root){
    queue* parent_queue = (queue*)malloc(sizeof(queue));
    parent_queue->front = NULL;
    parent_queue->rear = NULL;
    enqueue(parent_queue, root);
    
    queue* child_queue = (queue*)malloc(sizeof(queue));
    child_queue->front = NULL;
    child_queue->rear = NULL;
    
    helper(parent_queue, child_queue);
}
