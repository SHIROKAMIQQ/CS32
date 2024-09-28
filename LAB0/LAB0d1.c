#include <stdio.h>
#include <string.h>

long get_total(long h[], long w, long i, long j) {
    long total = 0;

    for(long p = i; p <= j; p++) {
        total += h[p];
    }
    total += (j-i+1)*w*2;
    return total;
}

void test_case(void) {
    long n;
    scanf("%ld", &n);

    long h[n];
    for (long n_ = 0; n_ < n; n_++) {
        scanf("%ld", &h[n_]); 
    }

    long waters = 0;
    char command[5];

    long q;
    scanf("%ld", &q);
    for (long q_ = 0; q_ < q; q_++) {
        scanf("%s", command);
        if (strcmp(command, "water") == 0) {
            waters++;
        } else if (strcmp(command, "total") == 0) {
            long i, j;
            scanf("%ld %ld", &i, &j);
            long total = get_total(h, waters, i-1, j-1);
            printf("%ld\n", total);
        }


    }
}

int main() {
    long t;
    scanf("%ld", &t);
    
    for (int t_ = 0; t_ < t; t_++) {
        test_case();
    }

    return 0;
}