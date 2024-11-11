#include "paths.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct ll_node {
    int val;
    struct ll_node* next;
} ll_node;

typedef struct stack {
    ll_node* top;
} stack;
void push(stack* s, int val){
    ll_node* newNode = (ll_node*)malloc(sizeof(ll_node));
    newNode->val = val;
    newNode->next = s->top;
    s->top = newNode;
}
int pop(stack* s){
    int v = s->top->val;
    ll_node* to_free = s->top;
    s->top = s->top->next;
    free(to_free);
    return v;
}

void visit(int city);

ll_node** make_adj_list(int n, int e, road* roads) {
    ll_node** a = (ll_node**)malloc((n+1)*sizeof(ll_node*));
    for (int i = 0; i <= n; i++) {a[i] = NULL;}

    for (int d = 0; d < e; d++) {
        ll_node* newNode1 = (ll_node*)malloc(sizeof(ll_node));
        newNode1->val = roads[d].city2;
        newNode1->next = a[roads[d].city1];
        a[roads[d].city1] = newNode1;

        ll_node* newNode2 = (ll_node*)malloc(sizeof(ll_node));
        newNode2->val = roads[d].city1;
        newNode2->next = a[roads[d].city2];
        a[roads[d].city2] = newNode2;
    }
    return a;
}

bool dfs(int n, ll_node** adj_list, bool** visited, stack* s, int city){
    if (city == n) {
        (*visited)[city-1] = true;
        push(s, city);
        return true;
    }
    if ((*visited)[city] == true){return false;}

    (*visited)[city] = true;

    while (adj_list[city] != NULL) {
        if (dfs(n, adj_list, visited, s, (adj_list[city])->val) == true){
            push(s, city);
            return true;
        } else {
            adj_list[city] = (adj_list[city])->next;
        }
    }
    return false;
}

void find_path(int n, int e, road* roads) {
    ll_node** adj_list = make_adj_list(n, e, roads);
    stack* s = (stack*)malloc(sizeof(stack));
    s->top = NULL;
    bool* visited = (bool*)malloc((n+1)*sizeof(bool));
    for (int i = 0; i <= n; i++) {visited[i] = false;}
    dfs(n, adj_list, &visited, s, 1);

    while (s->top != NULL) {
        visit(pop(s));
    }
}