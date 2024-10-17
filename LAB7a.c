#include "pre_post_order.h"
#include <stdlib.h>

void preorder(tree_node *root) {
    visit(root);
    ll_node* ll_child = root->children;
    while (ll_child != NULL) {
        preorder(ll_child->node);
        ll_child = ll_child->next;
    }
}

void postorder(tree_node *root) {
    ll_node* ll_child = root->children;
    while (ll_child != NULL) {
        postorder(ll_child->node);
        ll_child = ll_child->next;
    }
    visit(root);
}