#include "splice.h"
#include <stdio.h>
#include <stdlib.h>


struct node *splice(struct node **head, int i, int j) {
    
    if (i == 0) {
        struct node* right = *head;
        for (int moves = 0; moves < j-1; moves++) {
            right = right->next;
        }
        
        struct node* spliced_head = *head;
        *head = right->next;
        right->next = NULL;
        return spliced_head;
    }
    
    struct node* left = *head;
    struct node* right = *head;
    int difference = j - i;

    for (int moves = 0; moves < difference; moves++) {
        right = right->next;
    }
    printf("%d %d\n", left->val, right->val);
    for (int moves = 0; moves < i-1; moves++) {
        left = left->next;
        right = right->next;
    }
    printf("%d %d\n", left->val, right->val);

    struct node* spliced_head = left->next;
    left->next = right->next;
    right->next = NULL;

    return spliced_head;
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
    int dataset[11] = {0,1,2,3,4,5,6,7,8,9,10};
    struct node* linked_list1 = BuildLinkedList(dataset, 11);
    struct node* spliced_list = splice(&linked_list1, 3, 10);
    printf("SPLICED: ");
    PrintLinkedList(spliced_list);
    printf("ORIGINAL: ");
    PrintLinkedList(linked_list1);

    struct node* linked_list2 = BuildLinkedList(dataset, 11);
    struct node* spliced_list2 = splice(&linked_list2, 3, 11);
    printf("SPLICED: ");
    PrintLinkedList(spliced_list2);
    printf("ORIGINAL: ");
    PrintLinkedList(linked_list2);

    struct node* linked_list3 = BuildLinkedList(dataset, 11);
    struct node* spliced_list3 = splice(&linked_list3, 0, 10);
    printf("SPLICED: ");
    PrintLinkedList(spliced_list3);
    printf("ORIGINAL: ");
    PrintLinkedList(linked_list3);

    struct node* linked_list4 = BuildLinkedList(dataset, 11);
    struct node* spliced_list4 = splice(&linked_list4, 0, 11);
    printf("SPLICED: ");
    PrintLinkedList(spliced_list4);
    printf("ORIGINAL: ");
    PrintLinkedList(linked_list4);
}

