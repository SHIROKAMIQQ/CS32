#include "expr_parse.h"
#include <stdint.h>
#include <stdlib.h>

int64_t powten(int n);
int64_t parse_integer(int* arr, int length);

typedef struct linear_node {
    expr_node* operation_node;
    struct linear_node* next;
} linear_node;

expr_node* parse_expression(const char* s){
    if (!s[0]) {
        expr_node* empty_root = (expr_node*)malloc(sizeof(expr_node));
        empty_root = NULL;
        return empty_root;
    }
    linear_node* head = (linear_node*)malloc(sizeof(linear_node));
    head->next = NULL;
    expr_node* root = (expr_node*)malloc(sizeof(expr_node));
    root->ntype = OP;
    root->left = NULL;
    root->right = NULL;
    head->operation_node = root;
    int* number = (int*)malloc(16*sizeof(int));

    size_t i = 0;
    while (s[i]) {
        int chartype = (int)(s[i]);
        if (chartype == 32) { //SPACE 
            i++;
        } else if (chartype >= 97  && chartype <= 122){ //VARIABLE
            expr_node* newNode = (expr_node*)malloc(sizeof(expr_node));
            newNode->ntype = VAR;
            newNode->var = s[i++];
            if (head->operation_node->left == NULL) {head->operation_node->left = newNode;} 
            else {head->operation_node->right = newNode;}
        } else if (chartype >= 48 && chartype <= 57) { //VALUE
            int64_t num = 0;
            while (s[i] && ((int)(s[i]) >= 48 && (int)(s[i]) <= 57)) {
                num = (num* (int64_t)(10)) + ((int64_t)(s[i]) - 48);
                i++;
            }
            expr_node* newNode = (expr_node*)malloc(sizeof(expr_node));
            newNode->ntype = VAL;
            newNode->val = num;
            if (head->operation_node->left == NULL) {head->operation_node->left = newNode;}
            else {head->operation_node->right = newNode;}
            num = 0;
        } else if (chartype == 42) { //MULTIPLICATION
            head->operation_node->otype = MUL;
            i++;
        } else if (chartype == 43) { //ADDITION
            head->operation_node->otype = ADD;
            i++;
        } else if (chartype == 45) { //SUBTRACTION
            head->operation_node->otype = SUB;
            i++;
        } else if (chartype == 40) { //OPEN PARENTHESIS
            expr_node* newNode = (expr_node*)malloc(sizeof(expr_node));
            newNode->ntype = OP;
            newNode->left = NULL;
            newNode->right = NULL;
            if (head->operation_node->left == NULL) {head->operation_node->left = newNode;}
            else {head->operation_node->right = newNode;}
            linear_node* newTop = (linear_node*)malloc(sizeof(expr_node));
            newTop->operation_node = newNode;
            newTop->next = head;
            head = newTop;
            i++;
        } else if (chartype == 41) { //CLOSED PARENTHESIS
            head = head->next;
            i++;
        }
    }
    head;
    return head->operation_node;
}