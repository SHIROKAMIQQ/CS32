#include "mra.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

bool _is_leaf(mra_node *node) {
    return node->ri - node->li == 1;
}

int64_t _mra_get(mra_node *node, idx_t i) {
    assert(node->li <= i && i < node->ri);
    if (_is_leaf(node)) {
        return node->val;
    } else {
        return _mra_get((i < node->left->ri ? node->left : node->right), i);
    }
}

int64_t mra_get(min_ready_array *a, idx_t i) {
    assert(0 <= i && i < mra_size(a));
    return _mra_get(a->root, i);
}

void preorder_traversal(mra_node* root) {
    if (root == NULL) {return;}
    printf("[%d,%d)(%ld) || ", root->li, root->ri, root->val);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main() {
    int64_t data1[7] = {4, 0, 2, 1, 3, 7, 1};
    printf("{4, 0, 2, 1, 3, 7, 1}\n");
    size_t n1 = 7;
    min_ready_array* mra1 = mra_init(n1, data1);
    printf("mra_init: "); preorder_traversal(mra1->root); printf("\n");
    printf("Size: %d\n", mra_size(mra1));
    printf("Empty: %d\n", mra_empty(mra1));

    printf("\n");

    int64_t data2[6] = {4, 0, 2, 1, 3, 0};
    size_t n2 = 6;
    printf("{4, 0, 2, 1, 3, 0}\n");
    min_ready_array* mra2 = mra_init(n2, data2);
    printf("mra_init: "); preorder_traversal(mra2->root); printf("\n");
    printf("Size: %d\n", mra_size(mra2));
    printf("Empty: %d\n", mra_empty(mra2));

    printf("\n");

    int64_t data0[0] = {};
    size_t n0 = 0;
    printf("{}\n");
    min_ready_array* mra0 = mra_init(n0, data0);
    printf("mra_init: "); if (mra0->root == NULL) {printf("NULL");} else {preorder_traversal(mra2->root);} printf("\n");
    printf("Size: %d\n", mra_size(mra0));
    printf("Empty: %d\n", mra_empty(mra0));
}