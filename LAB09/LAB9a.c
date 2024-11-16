#include "downward_path.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

typedef struct ll_node{
    int val_i;
    int val_j;
    struct ll_node* next;   
} ll_node;

typedef struct stack{
    struct ll_node* top;
} stack;

void push(stack* s, int i, int j);
void push(stack* s, int i, int j){
    ll_node* newNode = (ll_node*)malloc(sizeof(ll_node));
    newNode->val_i = i;
    newNode->val_j = j;
    newNode->next = s->top;
    s->top = newNode;
}

ll_node* pop(stack* s);
ll_node* pop(stack* s){
    assert(s->top != NULL);
    ll_node* popped = s->top;
    s->top = s->top->next;
    return popped;
}

bool dfs(int r, int c, uint64_t** h, int i, int j, bool* visited, stack* s, uint64_t hprev);
bool dfs(int r, int c, uint64_t** h, int i, int j, bool* visited, stack* s, uint64_t hprev) {
    if (0 > i || i >= r || 0 > j || j >= c) {return false;}
    if (visited[i*c+j] == true) {return false;}
    if (hprev < h[i][j]) {return false;}

    visited[i*c + j] = true;
    if (i == r-1 && j == c-1) {
        push(s, i, j);
        return true;
    }

    bool path = false;
    path = (
        dfs(r, c, h, i+1, j, visited, s, h[i][j]) ||
        dfs(r, c, h, i-1, j, visited, s, h[i][j]) ||
        dfs(r, c, h, i, j-1, visited, s, h[i][j]) ||
        dfs(r, c, h, i, j+1, visited, s, h[i][j])
    );
    if (path == false) {
        return false; 
    } else {
        push(s, i, j);
        return true;
    }
}

bool find_downward_path(int r, int c, uint64_t** h) {

    bool* visited = (bool*)malloc(r*c*sizeof(bool));
    for (int i = 0; i < r*c; i++) {visited[i] = false;}

    stack* s = (stack*)malloc(sizeof(stack));
    s->top = NULL;

    bool path = dfs(r, c, h, 0, 0, visited, s, UINT64_MAX);

    while (s->top != NULL) {
        ll_node* popped = pop(s);
        visit(popped->val_i, popped->val_j);
        free(popped);
    }
    return path;
}