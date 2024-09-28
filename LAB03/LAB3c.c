#include "bucketize.h"
#include <stdlib.h>
#include <stdio.h>

struct node* BuildLinkedList(int* keyset, int* dataset, int length) {
    struct node dummy;
    dummy.key = 0;
    dummy.val = 0;
    dummy.next = NULL;
    struct node* current = &dummy;

    for (int i = 0; i < length; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->key = keyset[i];
        newNode->val = dataset[i];
        newNode->next = NULL;
        current->next = newNode;
        current = current->next;
        current->next = NULL;
    }

    return dummy.next;
}
void PrintLinkedList(struct node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    while (head != NULL) {
        printf("%d:%d ", head->key, head->val);
        head = head->next;
    }
    printf("\n");
}

int bucketize(struct node* head, struct node*** res) {
    struct node* current = head;
    int m = 0;
    while (current != NULL) {
        m = (current->key > m) ? current->key : m;
        current = current->next;
    }

    *res = malloc((m+1)*sizeof(struct node*));
    struct node** res_current = malloc((m+1)*sizeof(struct node*));
    for (int i = 0; i <= m; i++) {
        (*res)[i] = NULL;
        res_current[i] = (*res)[i];
    }

    current = head;
    while (current != NULL) {
        int k = current->key;
        struct node* temp = current->next;
        current->next = NULL;
        if ((*res)[k] == NULL) {
            (*res)[k] = current;
            res_current[k] = (*res)[k];
        } else {
            res_current[k]->next = current;
            res_current[k] = res_current[k]->next;
        }
        current = temp; 
    }

    return m+1;

}

int main() {
    int K1[5] = {3,1,4,1,5};
    int D1[5] = {1,2,3,4,5};
    struct node* L1 = BuildLinkedList(K1, D1, 5);
    struct node*** res1 = malloc(sizeof(struct node**));
    int ret1 = bucketize(L1, res1);
    /*printf("Size: %d\n", ret1);
    for (int i = 0; i < ret1; i++) {
        printf("%d: ", i);
        PrintLinkedList((*res1)[i]);
    }*/

    //printf("\n\n");
    int K2[200000];
    int D2[200000];
    for (int i = 1; i <= 200000; i++) {
        K2[i-1] = 1;
        D2[i-1] = i;
    }
    struct node* L2 = BuildLinkedList(K2, D2, 200000);
    struct node*** res2 = malloc(sizeof(struct node**));
    int ret2 = bucketize(L2, res2);
    /*printf("Size: %d\n", ret2);
    for (int i = 0; i < ret2; i++) {
        printf("%d: ", i);
        PrintLinkedList((*res2)[i]);
    }*/
}