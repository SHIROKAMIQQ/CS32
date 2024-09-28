#include "dominions.h"
#include <stdlib.h>

int64* dominions(int n, int64* h) {
    if (n == 0) {
        int64* ret = (int64*)malloc(0*sizeof(int64));
        return ret;
    }

    int64* rightrange = (int64*)malloc(n*sizeof(int64));
    int64* stack = (int64*)malloc(n*sizeof(int64));
    int top = 0;
    for (int64 i = n-1; i >= 0; i--) {
        while (1) {
            if (top == 0) {
                rightrange[i] = (n-1) - i;
                stack[top++] = i;
                break;
            } else if(h[i] >= h[stack[top-1]]) {
                top--;
            } else {
                rightrange[i] = stack[top-1] - 1 - i;
                stack[top++] = i;
                break;
            }
        }
    }
    
    int64* ret = (int64*)malloc(n*sizeof(int64));
    top = 0;
    for (int64 i = 0; i < n; i++) {
        while(1) {
            if (top == 0) {
                ret[i] = rightrange[i] + i + 1;
                stack[top++] = i;
                break;
            } else if (h[i] >= h[stack[top-1]]) {
                top--;
            } else {
                ret[i] = rightrange[i] + (i - stack[top-1]);
                stack[top++] = i;
                break;
            }
        }
    }

    return ret;
}