#include "excitingness.h"
#include <stdlib.h>
#include <stdio.h>

long long int excitingness(int n, long long int* l){
    if (n == 1) {
        return 0;
    }
    
    long long int niceness_sum = l[0];
    long long int pnk = 0;

    for (int i = 1; i < n-1; i++) {
        niceness_sum += l[i];
        if ((l[i-1] < l[i] && l[i+1] < l[i])
        || (l[i] < l[i-1] && l[i] < l[i+1])) {
            pnk++;
        }
    }
    niceness_sum += l[n-1];

    //printf("%lld %lld ", niceness_sum, pnk);
    return niceness_sum * pnk;
}

int main() {
    long long int D1[200000];
    for (int i = 1; i <= 200000; i++) {
        D1[i-1] = i; 
    }
    printf("%d\n", excitingness(200000, D1));
}