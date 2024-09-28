#include "reverse_circ.h"
#include <stdio.h>
#include <stdlib.h>

struct node *reverse(struct node **headRef) {
    struct node* x = *headRef; //x
    struct node* head = *headRef;
    struct node dummy;
    dummy.next = NULL;
    struct node* temp = dummy.next;

    while (head != NULL) { 
        temp = head;
        head = head->next;
        temp->next = dummy.next;
        dummy.next = temp;
    }

    x->next = dummy.next;
    return x;

}

void reverse_circ(struct node *x) {

    struct node* tail = x;
    while (tail->next != x) {
        tail = tail->next;
    }
    tail->next = NULL;

    struct node** xref = &x;
    reverse(xref);
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

    current->next = dummy.next;

    return dummy.next;
}

void PrintLinkedList(struct node* head) {
    struct node* current = head;
    printf("%d ", current->val);
    current = current->next;
    while (current != head){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int dataset[11] = {0,1,2,3,4,5,6,7,8,9,10};
    struct node* linked_list1 = BuildLinkedList(dataset, 11);
    reverse_circ(linked_list1);
    PrintLinkedList(linked_list1);

    int dataset2[1] = {1};
    struct node* linked_list2 = BuildLinkedList(dataset2, 1);
    reverse_circ(linked_list2);
    PrintLinkedList(linked_list2);

    int dataset3[2] = {1,2};
    struct node* linked_list3 = BuildLinkedList(dataset3, 2);
    reverse_circ(linked_list3);
    PrintLinkedList(linked_list3);
}