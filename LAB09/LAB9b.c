#include "task_order.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct ll_node{
    int val;
    struct ll_node* next;
} ll_node;

ll_node** make_adj_list(int n, int d, dependency* deps) {
    ll_node** ret = (ll_node**)malloc(n*sizeof(ll_node*));
    for (int i = 0; i < n; i++) {
        ret[i] = NULL;
    }
    for (int i = 0; i < d; i++) {
        ll_node* newNode = (ll_node*)malloc(sizeof(ll_node));
        newNode->val = (deps[i]).prerequisite_task;
        newNode->next = ret[(deps[i]).task];
        ret[(deps[i]).task] = newNode;
    }
    return ret;
}

void dfs(ll_node** adj_list, bool* visited, int* ret, int current_task, int* idx) {
    if (visited[current_task] == true) {
        return;
    }

    visited[current_task] = true;
    while (adj_list[current_task] != NULL) {
        dfs(adj_list, visited, ret, adj_list[current_task]->val, idx);
        adj_list[current_task] = adj_list[current_task]->next;
    }
    ret[(*idx)++] = current_task;
    return;
}

int* find_task_order(int n, int d, dependency* deps) {
    ll_node** adj_list = make_adj_list(n, d, deps);

    bool* visited = (bool*)malloc(n*sizeof(bool));
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int idx = 0;
    int* ret = (int*)malloc(n*sizeof(ret));

    dfs(adj_list, visited, ret, 0, &idx);

    for (int i = 0; i < n; i++){ 
        if (visited[i] == false) {
            dfs(adj_list, visited, ret, i, &idx);
        }
    }

    return ret;
}