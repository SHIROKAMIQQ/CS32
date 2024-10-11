#include "expr_print.h"

#include <stdio.h>
#include <stdlib.h>

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

void print_expression_ln(expr_node *node) {
    print_expression(node);
    printf("\n");
}
int main() {
    expr_node *a = _var('a');
    expr_node *b = _var('b');
    expr_node *c = _var('c');
    print_expression_ln(  // b^2 - 4ac
        _sub(
            _mul(b, b),
            _mul(
                _val(4),
                _mul(a, c)
            )
        )
    );
    expr_node *x = _var('x');
    print_expression_ln(  // (x - 143)(x + 143)
        _mul(
            _sub(x, _val(143)),
            _add(x, _val(143))
        )
    );
    expr_node *y = _var('y');
    print_expression_ln(  // y - y
        _sub(y, y)
    );
    expr_node *one = _val(1);
    expr_node *three = _add(_add(one, one), one);
    print_expression_ln(  // (1 - 1)(1 + 1 + 1)(1 + 1 + 1)
        _mul(
            _sub(one, one),
            _mul(three, three)
        )
    );

    ... // TODO add more testing code here
}