#include "stroll.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct ll_node{
    int val;
    struct ll_node* next;
} ll_node;

ll_node** make_adj_list(int n, int r, road* roads);
ll_node** make_adj_list(int n, int r, road* roads) {
    ll_node** adj_list = (ll_node**)malloc(n*sizeof(ll_node*));
    for (int i = 0; i < n; i++) {
        adj_list[i] = NULL;
    }
    for (int j = 0; j < r; j++) {
        ll_node* newNode = (ll_node*)malloc(sizeof(ll_node));
        newNode->val = roads[j].end;
        newNode->next = adj_list[roads[j].start];
        adj_list[roads[j].start] = newNode;
    }

    return adj_list;
}

void update_longest_path(int* longest_path, int* current_path, int size);
void update_longest_path(int* longest_path, int* current_path, int size) {
    for (int i = 0; i < size; i++) {
        longest_path[i] = current_path[i];
    }
}

void dfs(ll_node** adj_list, bool* visited, int* current_size, int* longest_size, int* current_path, int* longest_path, int current_node);
void dfs(ll_node** adj_list, bool* visited, int* current_size, int* longest_size, int* current_path, int* longest_path, int current_node) {
    if (current_node == 1) {
        current_path[(*current_size)++] = current_node;
        if ((*current_size) > (*longest_size)) {
            update_longest_path(longest_path, current_path, *current_size);
        (*longest_size) = (*current_size);
        }
        (*current_size)--;
        return;
    }

    if (visited[current_node] == true) {return;}

    current_path[(*current_size)++] = current_node;
    visited[current_node] = true;
    ll_node* current_adj = adj_list[current_node];
    while (current_adj != NULL) {
        dfs(adj_list, visited, current_size, longest_size, current_path, longest_path, current_adj->val);
        current_adj = current_adj->next;
    }
    (*current_size)--;
    visited[current_node] = false;
}

void find_leisurely_path(int n, int r, road *roads){
    int current_size = 0;
    int longest_size = 0;
    int* longest_path = (int*)malloc(n*sizeof(int));
    int* current_path = (int*)malloc(n*sizeof(int));
    bool* visited = (bool*)calloc(n, sizeof(int));

    ll_node** adj_list = make_adj_list(n, r, roads);
    dfs(adj_list, visited, &current_size, &longest_size, current_path, longest_path, 0);   
    for (int i = 0; i < longest_size; i++) {
        visit(longest_path[i]);
    }
} 