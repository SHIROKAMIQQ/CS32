#include "distance.h"
#include <stdio.h>
#include <stdlib.h>

int distance(struct node *a, struct node *b){
    struct node* a_ = a;
    struct node* b_ = b;
    int d = 0;

    if (a == b) {
        return 0;   
    }

    while (a_ != NULL && b_ != NULL && a_ != b && b_ != a) {
        a_ = a_->next;
        b_ = b_->next;
        d++;
    }
    if (a_ == b || b_ == a) {
        return d;
    } else if (a_ == NULL) {
        while (b_ != a) {
            b_ = b_->next;
            d++;
        }
        return d;
    } else if (b_ == NULL) {
        while (a_ != b) {
            a_ = a_->next;
            d++;
        }
        return d;
    }
}


struct node* BuildLinkedList(int* dataset, int length) {
    if (length == 0) {
        return NULL;
    }
    
    struct node dummy;
    struct node* current = &dummy; 

    for (int i = 0; i < length; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
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
        printf("NULL");
    }

    while (head != NULL){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int dataset[10] = {0,1,2,3,4,5,6,7,8,9};
    struct node* linked_list = BuildLinkedList(dataset, 10);
    struct node* nodes[10];
    struct node* current = linked_list;
    for (int i = 0; i < 10; i++) {
        nodes[i] = current;
        current = current->next;
    }
    printf("%d\n", distance(nodes[2], nodes[7]));
    printf("%d\n", distance(nodes[7], nodes[2]));
}