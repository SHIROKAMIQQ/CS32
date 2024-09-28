#include "baggage.h"
#include <stdbool.h>
#include <stdio.h>

/*
bool within_limit(int l, int w, int h, long long int b) {
    long long int l_ = l, w_ = w, h_ = h;
    long long int p = l_*w_*h_;
    printf("%lld %lld", p, b);
    if (p < b) {
        printf("TRUE");
        return true;
    } else {
        printf("FALSE");
        return false;
    }

}
*/

bool within_limit(int l, int w, int h, long long int b) {
    long long int l_ = l, w_ = w, h_ = h;
    long long int a = l_*w_, c = b/h_;
    if (b % h_ != 0) {
        c++;
    }
    printf("%lld %lld", a, c);
    if (a < c) {
        printf("TRUE");
        return true;
    } else {
        printf("FALSE");
        return false;
    }

}

int main() {
    int six = 1000000;
    long long int eighteen = 1000000000000000000;
    double eighteenf = eighteen;
    printf("%lld %lf\n", 3*eighteen, 3*eighteenf);
    printf("%d %lld\n\n", six, eighteen);
    printf("%d\n", within_limit(2, 3, 4, 23));//FALSE
    printf("%d\n", within_limit(2, 3, 4, 24));//FALSE
    printf("%d\n", within_limit(2, 3, 4, 25));//TRUE
    printf("%d\n", within_limit(six, six, six, eighteen));//FALSE
    printf("%d\n", within_limit(six, six, 999999, eighteen));//TRUE
    printf("%d\n", within_limit(999999, 999999, 999999, eighteen));//TRUE
    printf("%d\n", within_limit(999999, 999999, 1, eighteen));//TRUE
    printf("%d\n", within_limit(999999, 999999, 999999, 1));//FALSE
}