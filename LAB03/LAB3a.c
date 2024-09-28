#include "reverse2.h"
#include <stdlib.h>

struct node *reverse(struct node *head) {
    if(head == NULL){
        return NULL;
    }
    
    struct node dummy;
    dummy.val = 0;
    dummy.next = NULL;
    dummy.prev = NULL;

    struct node* temp;
    dummy.next = head;
    head = head->next;
    (dummy.next)->next = NULL;

    while (head != NULL) {
        head->prev = NULL;
        temp = head->next;
        head->next = dummy.next;
        (dummy.next)->prev = head;
        dummy.next = head;
        head = temp;
    }

    return dummy.next;
}