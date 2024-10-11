#include "expr_count.h"
#include <stdlib.h>
#include <stdint.h>

int64_t terms_in_expansion(expr_node *expr) {
    if (expr == NULL) {
        return 0;
    } else if (expr->ntype == VAR || expr->ntype == VAL) {
        return 1;
    } else if(expr->ntype == OP) {
        int64_t left_expressions = terms_in_expansion(expr->left);
        int64_t right_expressions = terms_in_expansion(expr->right);
        if (expr->otype == ADD || expr->otype == SUB) {
            return (left_expressions + right_expressions) % 323;
        } else {
            return (left_expressions * right_expressions) % 323;
        }
    }
}