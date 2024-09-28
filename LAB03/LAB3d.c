#include "even.h"
#include <stdlib.h>

struct node *even(struct node *head) {
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL) {
        return head;
    }
    
    struct node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->val % 2 == 0) {
            current = current->next;
        } else {
            if (current->next->val % 2 == 0) {
                current = current->next;
            } else {
                struct node* newNode = (struct node*)malloc(sizeof(struct node));
                newNode->val = 2;
                newNode->next = current->next;
                current->next = newNode;
                current = current->next->next;
            }
        }
    }

    return head;
}