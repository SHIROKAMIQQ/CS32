#include <stdlib.h>
#include <stdio.h>

struct node {
    int val;
    struct node* next;
};

struct node* BuildLinkedList(int* dataset, int length) {
    struct node dummy;
    dummy.val = 0;
    dummy.next = NULL;
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
        return;
    }

    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void PrintList(int* arr, int length) {
    if (length == 0) {
        printf("NULL");
        return;
    }

    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}