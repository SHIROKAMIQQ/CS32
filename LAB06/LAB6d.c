#include "bst_slice.h"
#include <stdlib.h>
#include <stdint.h>

size_t inorder(bst_node* bst, int64_t x, int64_t y, int64_t* res, int64_t* i);
size_t inorder(bst_node* bst, int64_t x, int64_t y, int64_t* res, int64_t* i){
    if (bst == NULL) {return 0;}
    size_t length = 0;

    if (bst->val >= x) {
        length += inorder(bst->left, x, y, res, i);
    }
    if (bst->val >= x && bst->val <= y) {
        res[(*i)++] = bst->val;
        length++;
    }
    if(bst->val <= y) {
        length += inorder(bst->right, x, y, res, i);
    }
    return length;
}

size_t bst_slice(bst_node *bst, int64_t x, int64_t y, int64_t *res){    
    int64_t i = 0;
    int64_t* ptr = &i;
    size_t length = inorder(bst, x, y, res, ptr);
    return length;
}