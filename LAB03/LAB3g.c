#include "excitingness_sum.h"
#include <stdlib.h>
#include <stdio.h>

int is_pk(int i, int64* l);
int is_pk(int i, int64* l) {
    if ((l[i] > l[i-1] && l[i] > l[i+1]) || (l[i] < l[i-1] && l[i] < l[i+1])) return 1;
    return 0;
}

int64 excitingness_sum(int n, int64 *l){
    int64 ret = 0;

    int64 prefix_sum = 0;
    for (int i = 1; i < n-1; i++){ 
        prefix_sum += l[i-1] * i;
        if (is_pk(i, l)) {
            ret = (ret + prefix_sum*(n-i-1)) % 1000000000;
            ret = (ret + l[i]*i*(n-i-1)) % 1000000000;
        }
    }

    int64 suffix_sum = 0;
    for (int i = n-2; i > 0; i--) {
        suffix_sum += l[i+1] * (n-i-1);
        if (is_pk(i, l)) {
            ret = (ret + suffix_sum*i) % 1000000000;
        }
    }

    return ret;
}

int main(){
    int64 D1[11] = {1,3,4,4,4,2,6,1,2,5,1};
    printf("%d\n", excitingness_sum(11, D1));
}