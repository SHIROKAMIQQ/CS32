#include <stdlib.h>
#include <stdio.h>

void PrintList(int* arr, int length) {
    if (length == 0) {
        printf("NULL\n");
        return;
    }
    
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

struct node{
    char val;
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
        printf("NULL\n");
        return;
    }

    while (head != NULL) {
        printf("%c", head->val);
        head = head->next;
    }
    printf("\n");
}
struct node* reverse(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    
    struct node* current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    int dataset[length];
    current = head;
    for (int i = length-1; i >= 0; i--) {
        dataset[i] = current->val;
        current = current->next;
    }
    return BuildLinkedList(dataset, length);
}

/*
struct stack{
    int size;
    int top;
    int* arr;
};
struct stack* InitStack(int s) {
    struct stack* ret;
    ret->size = s;
    ret->top = 0;
    ret->arr = (int*)malloc(s*sizeof(int));
    return ret;
}
int IsEmptyStack(struct stack* s) {
    return(s->top == 0);
}
void Push(struct stack* s, int x) {
    if (s->top == s->size){
        printf("STACK OVERFLOW\n");
        return;
    }
    (s->arr)[s->top] = x;
    (s->top)++;
}
void Pop(struct stack* s, int** x) {
    if (s->top == 0) {
        printf("STACK UNDERFLOW\n");
        return;
    }
    (s->top)--;
    *x = (int*)malloc(sizeof(int));
    **x = (s->arr)[s->top];
}
void PrintStack(struct stack* s) {
    PrintList(s->arr, s->top);
}*/

struct stack{
    struct node* top;
};
struct stack* InitStack() {
    struct stack* ret;
    ret->top = (struct node*)malloc(sizeof(struct node));
    ret->top = NULL;
    return ret;
}
int IsEmptyStack(struct stack* s) {
    return (s->top == NULL);
}
void Push(struct stack* s, int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = x;
    struct node* temp = s->top;
    newNode->next = temp;
    s->top = newNode;
}
void Pop(struct stack* s, int** x) {
    if (s->top == NULL) {
        *x = NULL;
        printf("STACK UNDERLOAD\n");
        return;
    }
    *x = (int*)malloc(sizeof(int));
    **x = s->top->val;
    s->top = s->top->next;
}
void PrintStack(struct stack* s) {
    PrintLinkedList(reverse(s->top));
}
//Comment
