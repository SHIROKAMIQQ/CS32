#include "mra.h"
#include <stdlib.h>
#include <stdint.h>

mra_node* recursive_init(int64_t* data, size_t i, size_t j) {
    mra_node* root = (mra_node*)malloc(sizeof(mra_node));
    root->li = i;
    root->ri = j;
    if (j-i == 1) {
        root->val = data[i];
        root->left = NULL;
        root->right = NULL;
    } else {
        size_t mid = (i+j)/2;
        root->left = recursive_init(data, i, mid);
        root->right = recursive_init(data, mid, j);
        root->val = (root->left->val <= root->right->val) ? root->left->val : root->right->val;
    }
    return root;
}

min_ready_array* mra_init(size_t n, int64_t* data) {
    min_ready_array* mra = (min_ready_array*)malloc(sizeof(min_ready_array));
    if (n == 0) {mra->root = NULL;}
    else {mra->root = recursive_init(data, 0, n);}
    return mra;
}
int64_t mra_min_range(min_ready_array *a, idx_t i, idx_t j);

int32_t mra_size(min_ready_array *a) {
    if (a->root = NULL){return 0;}
    else{return 2*(a->root->ri) - 1;}
}
bool mra_empty(min_ready_array *a){
    return (mra_size(a) == 0) ? true : false;
}