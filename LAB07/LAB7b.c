#include "level_order.h"
#include <stdlib.h>

typedef struct stack {
    ll_node* top;
} Stack;

void helper(Stack* parent_stack, Stack* child_stack);
void helper(Stack* parent_stack, Stack* child_stack) {
    if (parent_stack->top == NULL) {return;}

    while (parent_stack->top != NULL) {
        visit(parent_stack->top->node);

        ll_node* current_child = parent_stack->top->node->children;
        while (current_child != NULL) {
            ll_node* ch = (ll_node*)malloc(sizeof(ll_node));
            ch->node = current_child->node;
            ch->next = child_stack->top;
            child_stack->top = ch;
            current_child = current_child->next;
        }

        parent_stack->top = parent_stack->top->next;
    }

    while (child_stack->top != NULL) {
        ll_node* temp = child_stack->top;
        child_stack->top = child_stack->top->next;
        temp->next = parent_stack->top;
        parent_stack->top = temp;
    }

    helper(parent_stack, child_stack);
}

void levelorder(tree_node *root){
    Stack* parent_stack = (Stack*)malloc(sizeof(Stack));
    parent_stack->top = NULL;

    ll_node* ll_root = (ll_node*)malloc(sizeof(ll_node));
    ll_root->node = root;
    ll_root->next = NULL;
    parent_stack->top = ll_root;

    Stack* child_stack = (Stack*)malloc(sizeof(Stack));
    child_stack->top = NULL;

    helper(parent_stack, child_stack);
}