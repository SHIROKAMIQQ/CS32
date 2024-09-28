#include "sorted_streaks.h"
#include <stdio.h>
#include <stdlib.h>

int sorted_streaks(struct node *head, struct node **result){
    
    int streaks = 0;

    result[0] = head;
    struct node* previous = head;
    head = head->next;
    
    while (head != NULL) {
        if (head->val < previous->val) {
            previous->next = NULL;
            result[++streaks] = head;
        }
        previous = head;
        head = head->next;
    }

    return ++streaks;
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
    int dataset[11] = {3,1,2,2,5,6,1,4,5,5,3}; // [[3],[1,2,2,5,6],[1,4,5,5],[3]]
    struct node* linked_list1 = BuildLinkedList(dataset, 11);
    struct node** result;
    int streaks = sorted_streaks(linked_list1, result);
    printf("%d\n", streaks);
    for (int i = 0; i < streaks; i++) {
        PrintLinkedList(result[i]);
    }

    /*
    printf("\n\n");
    int dataset2[1] = {3}; // [[3]]
    struct node* linked_list2 = BuildLinkedList(dataset2, 1);
    struct node* result2[1];
    int streaks2 = sorted_streaks(linked_list2, result2);
    printf("%d\n", streaks2);
    for (int i = 0; i < streaks2; i++) {
        PrintLinkedList(result[i]);
    }*/
    
}