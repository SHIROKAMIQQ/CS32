#include "reverse.h"
#include <stdio.h>
#include <stdlib.h>

struct node *reverse(struct node *head) {

    if (head == NULL) {
        return head;
    }
    
    struct node dummy;
    dummy.next = NULL;
    struct node* temp = dummy.next;

    while (head != NULL) { 
        temp = head;
        head = head->next;
        temp->next = dummy.next;
        dummy.next = temp;
    }

    return dummy.next;

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

struct node* BuildLL(int length) {
    struct node dummy;
    dummy.next = NULL;
    struct node* current = &dummy;

    for (int i = 0; i < length; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->val = i;
        newNode->next = NULL;
        current->next = newNode;
        current = current->next;
    }
    
    return dummy.next;
}

int main() {
    int dataset[10] = {1,2,3,4,5,6,7,8,9,10};
    struct node* linked_list1 = BuildLinkedList(dataset, 10);
    struct node* reversed = reverse(linked_list1);
    PrintLinkedList(reversed);
    PrintLinkedList(linked_list1);
}