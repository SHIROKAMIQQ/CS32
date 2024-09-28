#include "all_nearest_smaller.h"
#include <stdlib.h>

int* all_nearest_smaller(int n, int64* s) {
    if (n == 0) {
        int* ret = (int*)malloc(0*sizeof(int));
        return ret;
    }
    
    int* stacki = (int*)malloc(n*sizeof(int));
    int top = 0;

    int* ret = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        while (1) {
            if (top == 0) {
                ret[i] = -1;
                stacki[top] = i;
                top++;
                break;
            } else {
                if (s[stacki[top-1]] < s[i]) {
                    ret[i] = stacki[top-1];
                    stacki[top] = i;
                    top++;
                    break;
                } else {
                    top--;
                }
            }
        }
    }
    return ret;
}