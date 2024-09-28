#include "imbalances.h"
#include <stdlib.h>

int64* imbalances(int n, int64* s) {
    int64 total = 0;
    for (int i = 0; i < n; i++) {
        total += s[i];
    }

    int64* ret = (int64*)malloc((n-1)*sizeof(int64));
    int64 left = 0;
    int64 right = total;
    for (int i = 1; i < n; i++) {
        left += s[i-1];
        right -= s[i-1];
        int64 diff = right*right - left*left;
        ret[i-1] = (diff >= 0) ? diff : -diff;
    }
    return ret;
}