#include "tour.h"
#include <stdlib.h>

void tour(tree_node *root){
    visit(root);
    ll_node* ll_child = root->children;
    while (ll_child != NULL) {
        tour(ll_child->node);
        visit(root);
        ll_child = ll_child->next;
    }
}