#include "distribute.h"
#include <stdlib.h>
#include <stdio.h>

struct node{ 
    char val;
    struct node* next;
};
typedef struct node Node;

char ctype(const char c){
    if (c == ')') {
        return 'p';
    } else if (c == '+' || c == '-') {
        return 'o';
    } else {
        return 'l';
    }
}

char *distribute(const char *e) {
    Node* stack = (Node*)malloc(sizeof(Node));
    stack = NULL;
    char current_sign = '+';

    Node dummy;
    dummy.val = '\0';
    dummy.next = NULL;
    Node* current = &dummy;
    int length = 0;

    for (int i = 0; e[i]; i++) {
        if (e[i] == '(') {
            if (i == 0 || (e[i-1] != '+' && e[i-1] != '-')){
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->val = '+';
                newNode->next = stack;
                stack = newNode;
                current_sign = (current_sign == stack->val) ? '+' : '-';
            }
            continue;
        } 
        char type = ctype(e[i]);
        if (type == 'l'){
            if (i == 0 || (e[i-1] != '+' && e[i-1] != '-')) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->val = '+';
                newNode->next = stack;
                stack = newNode;
                current_sign = (current_sign == stack->val) ? '+' : '-';
            }
            if (dummy.next != NULL) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->val = current_sign;
                newNode->next = NULL;
                current->next = newNode;
                current = current->next;
                length++;
            }
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->val = e[i];
            newNode->next = NULL;
            current->next = newNode;
            current = current->next;
            length++;
            current_sign = (current_sign == stack->val) ? '+' : '-';
            stack = stack->next;
        } else if (type == 'p') {
            current_sign = (current_sign == stack->val) ? '+' : '-';
            stack = stack->next;
        } else if (type == 'o') {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->val = e[i];
            newNode->next = stack;
            stack = newNode;
            current_sign = (current_sign == stack->val) ? '+' : '-';
        }
    }
    char* ret = (char*)malloc(length*sizeof(char));
    current = dummy.next;
    int i = 0;
    while (current != NULL) {
        ret[i++] = current->val;
        current = current->next;
    }
    return ret;

}

int main() {
    distribute("a+((x+y)-(w+z-a-(b+x)))");
    distribute("(a+s)-s");
    distribute("a+b");
    distribute("a");
    distribute("-(a+b)");
}