#include "eye.h"

long long int eye_count (long long int *s, int n) {

    long long int total_count = 0;
    for (int i = 0; i <= n-3; i++) {
        long long int sub_count = 0;
        for (int j = i+1; j < n; j++) {
            if (s[j] > s[i]) {
                sub_count++;
            } else if (s[j] == s[i]) {
                total_count += sub_count;
            }
        }
    }
    return total_count;
}