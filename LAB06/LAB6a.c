#include "expr_print.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void print_expression(expr_node *expr){
    if (expr == NULL) {
        printf("\0");
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