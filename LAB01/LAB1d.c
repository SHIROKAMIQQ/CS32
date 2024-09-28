#include "baggage4.h"
#include <stdio.h>

long long int max_vol_suitcase(long long int b, suitcase_t *s, int n){
    long long int max = 0;
    for (int i = 0; i < n; i++) {
        long long int sl = s[i].l, sw = s[i].w, sh = s[i].h;
        long long int candidate_sum = sl + sw + sh;
        if (candidate_sum <= b) {
            long long int candidate_p = sl * sw * sh;
            if (candidate_p > max) {
                max = candidate_p;
            }
        }
    }
    printf("%lld", max);
    return max;
}

int main() {
    int a = 1000000, b = 1000000, c = 1000000;
    long long int a_ = a, b_ = b, c_ = c;
    printf("%lld %lld %lld\n", a_, b_, c_);
    long long int p = a_*b_*c_;
    printf("%lld\n\n", p);
    
    suitcase_t s[] = {{1, 1, 1}, {a, b, c}};
    max_vol_suitcase(3000000, s, 2); //60
    //max_vol_suitcase(1, {{3, 1, 4}, {1, 5, 9}, {2, 6, 5}, {3, 5, 8}, {9, 7, 9}, {3, 2, 3}}, 6); // 0
}