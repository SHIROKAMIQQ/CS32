#include "baggage3.h"
#include <stdlib.h>
#include <stdio.h>

suitcase_t better_suitcase(suitcase_t s1, suitcase_t s2) {
    double s1l = s1.l, s2l = s2.l, s1w = s1.w, s2w = s2.w, s1h = s1.h, s2h = s2.h;
    double p1 = (s1l*s1w)/s2h;
    double p2 = s2l*s2w/s1h;
    printf("%lf %lf ", p1, p2);
    if (p1 >= p2) {
        printf("S1\n");
        return s1;
    } else {
        printf("S2\n");
        return s2;
    }
}

int main() {
    int six = 1000000;
    suitcase_t s314 = {3, 1, 4}, s222 = {2,2,2}, ssix = {six, six, six}, s9 = {999999,999999,999999};
    better_suitcase(s314, s222);
    better_suitcase(ssix, s9);
    //better_suitcase({3, 1, 4}, {2, 2, 3});
    //better_suitcase({3, 1, 4}, {2, 2, 4});

}