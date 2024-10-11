#include "expr_count.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VERIFY(b) do {\
    fprintf(stderr, "verifying: %s\n", (#b));\
    bool _b = (b);\
    if (!_b) {\
        fprintf(stderr, "verification failed!\n");\
        exit(1);\
    }\
} while (0)

expr_node *_val(uint64_t val) {
    expr_node *node = (expr_node*)malloc(sizeof(expr_node));
    node->ntype = VAL;
    node->val = val;
    return node;
}

expr_node *_var(char var) {
    expr_node *node = (expr_node*)malloc(sizeof(expr_node));
    node->ntype = VAR;
    node->var = var;
    return node;
}

expr_node *_op(op_type otype, expr_node *l, expr_node *r) {
    expr_node *node = (expr_node*)malloc(sizeof(expr_node));
    node->ntype = OP;
    node->otype = otype;
    node->left = l;
    node->right = r;
    return node;
}

expr_node *_add(expr_node *l, expr_node *r) { return _op(ADD, l, r); }
expr_node *_sub(expr_node *l, expr_node *r) { return _op(SUB, l, r); }
expr_node *_mul(expr_node *l, expr_node *r) { return _op(MUL, l, r); }

int main() {
    expr_node *a = _var('a');
    expr_node *b = _var('b');
    expr_node *c = _var('c');
    VERIFY(terms_in_expansion(_sub(_mul(b, b), _mul(_val(4), _mul(a, c)))) == 2);
    expr_node *x = _var('x');
    VERIFY(terms_in_expansion(_mul(_sub(x, _val(143)), _add(x, _val(143)))) == 4);
    expr_node *y = _var('y');
    VERIFY(terms_in_expansion(_sub(y, y)) == 2);
    expr_node *one = _val(1);
    expr_node *three = _add(_add(one, one), one);
    VERIFY(terms_in_expansion(_mul(_sub(one, one), _mul(three, three))) == 18);

    // TODO add more testing code here

    printf("test passed!\n");
}
