#include <stdio.h>
#include <string.h>

void magtanim(long long int n, long long int* h, long long int q){
    long long int prefix[n+1];
    prefix[0] = 0;
    for (long long int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + h[i-1];
    }

    long long int waters = 0;
    for (long long int q_ = 0; q_ < q; q_++) {
        char command[5];
        scanf("%s", command);
        if (strcmp(command, "water") == 0) {
            waters++;
        } else if (strcmp(command, "total") == 0) {
            long long int i, j;
            scanf("%lld %lld", &i, &j);
            long long int total = ((j-i+1)*waters*2) + (prefix[j]-prefix[i]+h[i-1]);
            printf("%lld\n", total);
        }
    }
}


long long int main() {
    long long int t;
    scanf("%lld", &t);

    for (long long int t_ = 0; t_ < t; t_++) {
        long long int n;
        scanf("%lld", &n);
        long long int h[n];
        for (long long int n_ = 0; n_ < n; n_++) {
            long long int temp;
            scanf("%lld", &temp);
            h[n_] = temp;
        }
        long long int q;
        scanf("%lld", &q);
        magtanim(n, h, q);
    }
}