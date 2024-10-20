#include "tour.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void visit(tree_node *node) {
    printf("visiting node with value %" PRId64 "\n", node->value);
}

tree_node *_tree_node(int64_t value, ll_node *children) {
    tree_node *node = (tree_node*)malloc(sizeof(tree_node));
    node->value = value;
    node->children = children;
    return node;
}

ll_node *_ll_node(tree_node *child, ll_node *next) {
    ll_node *node = (ll_node*)malloc(sizeof(ll_node));
    node->node = child;
    node->next = next;
    return node;
}

int main() {

    // construct a tree by appending each node to its parent
    int parent[9] = {-1, 0, 0, 0, 1, 1, 1, 3, 6};
    tree_node *nodes[9];
    for (int i = 0; i < 9; i++) {
        nodes[i] = _tree_node(i*10, NULL);
        if (i > 0) {
            int p = parent[i];
            nodes[p]->children = _ll_node(nodes[i], nodes[p]->children);
        }
    }

    tree_node *root = nodes[0];

    printf("Euler tour:\n");
    tour(root);

    // TODO add more testing code here
}