#include "expr_parse.h"

#include <stdbool.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#define VERIFY(b) do {\
    fprintf(stderr, "verifying: %s\n", (#b));\
    bool _b = (b);\
    if (!_b) {\
        fprintf(stderr, "verification failed!\n");\
        exit(1);\
    }\
} while (0)

// include similar functions and constructors as in lab06a here
void print_expression(expr_node *expr){
    if (expr == NULL) {
        printf("NULL");
        return;
    }

    if (expr->ntype == VAR) {
        printf("%c", expr->var);
    } else if (expr->ntype == VAL) {
        printf("%" PRIu64, expr->val);
    } else if (expr->ntype == OP) {
        if (expr->left->ntype == OP) {printf("(");}
        print_expression(expr->left);
        if (expr->left->ntype == OP) {printf(")");}

        if (expr->otype == ADD) {printf(" + ");}
        else if (expr->otype == SUB) {printf(" - ");}
        else if (expr->otype == MUL) {printf(" * ");}

        if (expr->right->ntype == OP) {printf("(");}
        print_expression(expr->right);
        if(expr->right->ntype == OP) {printf(")");}
    }
}
void print_expression_ln(expr_node *node) {
    print_expression(node);
    printf("\n");
}

int evaluate(const char* s){
    printf("ORIGINAL  : %s\n", s);
    printf("CONVERTED : "); print_expression(parse_expression(s)); printf("\n");
}

int main() {
    evaluate("y - y");
    evaluate("(x - 143) * (x + 143)");
    evaluate("(1 - 1) * (((1 + 1) + 1) * ((1 + 1) + 1))");
    evaluate("(b * b) - (4 * (a * c))");
    evaluate("(1234567812345678 * a) + 8765432187654321");
    evaluate("123 + 123445");
    evaluate("123 + 123445");
    evaluate("9 + a");
    evaluate("0 + a");
    evaluate("1 + 9");
    evaluate("012345678912345678901234567890 + 1234567890");
    evaluate("1 + 9");

    // TODO add more testing code here

    printf("test passed!\n");
}
