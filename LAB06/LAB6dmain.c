#include "bst_slice.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define VERIFY(b) do {\
    fprintf(stderr, "verifying: %s\n", (#b));\
    bool _b = (b);\
    if (!_b) {\
        fprintf(stderr, "verification failed!\n");\
        exit(1);\
    }\
} while (0)

void bst_insert(bst_node** B, int val){
    bst_node* current = *B;
    bst_node* temp = NULL;
    while (current != NULL) {
        if (val == current->val) return; //Duplicate val found; stop.
        else if (val > current->val) {
            temp = current;
            current = current->right;
        }
        else if (val < current->val) {
            temp = current;
            current = current->left;
        }
    }
    bst_node* newNode = (bst_node*)malloc(sizeof(bst_node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    if (temp == NULL) *B = newNode;
    else if (val < temp->val) temp->left = newNode;
    else if (val > temp->val) temp->right = newNode;
}

bst_node** bst_init(int* arr, int length) {
    //int nodes_to_insert = sizeof(arr)/sizeof(int);
    bst_node** BST = (bst_node**)malloc(sizeof(bst_node*));
    *BST = NULL;
    for (int i = 0; i < length; i++) {
        bst_insert(BST, arr[i]);
    }
    return BST;
}

void inorder_traversal(bst_node** B) {
    bst_node* root = *B;
    if (root != NULL) {
        inorder_traversal(&(root->left));
        printf("%d ", root->val);
        inorder_traversal(&(root->right));
    } 
}

void PrintList(int64_t* arr, size_t length) {
    if (length == 0) {printf("NULL");}

    for (int i=0; i < length; i++) {
        printf("%ld ", arr[i]);
    }
}

int main() {
    int arr1[1] = {1};
    bst_node** bst1 = bst_init(arr1, 1);
    int64_t* res1 = (int64_t*)malloc(1*sizeof(int64_t));
    size_t ret1 = bst_slice(*bst1, 1, 1, res1);
    printf("ORIGINAL: "); inorder_traversal(bst1); printf("\n"); 
    printf("SPLICED SIZE: %zu\n", ret1);
    printf("SPLICE 1 to 1: "); PrintList(res1, ret1); printf("\n");
}