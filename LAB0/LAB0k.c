#include <stdio.h>

long sum(long s[], long n) {
    long ret = 0;
    for (long n_ = 0; n_ < n; n_++) {
        ret += s[n_];
    }
    return ret;
}
void PrintList(long list[], long len) {
    for (int i = 0; i < len; i++) {
        printf("%ld\n", list[i]);
    }
}
long competitive_catherine(long s[], long n) {
    long odds[n];
    long evens[n];
    long oi = 0, ei = 0;
    for (long n_ = 0; n_ < n; n_++) {
        if (s[n_] % 2 == 0) {
            evens[ei] = s[n_];
            ei++;
        } else {
            odds[oi] = s[n_];
            oi++;
        }
    }
    long odds_len = oi, evens_len = ei;
    long odds_total = sum(odds, odds_len), evens_total = sum(evens, evens_len);
    long odds_total_temp = odds_total, evens_total_temp = evens_total, evens_len_temp = evens_len;

    long competitive_total = 0;
    
    //printf("ODDS\n");
    for (oi = 0; oi < odds_len; oi++) {
        odds_total_temp -= odds[oi];
        competitive_total = (competitive_total + (odds[oi]*odds_total_temp)) % (1000000000);
        //printf("%ld\n", competitive_total);
    }
    //printf("EVENS\n");
    for (ei = 0; ei < evens_len; ei++) {
        competitive_total = (competitive_total + ((evens[ei]+1)*(odds_total+odds_len))) % (1000000000);
        //printf("%ld\n", competitive_total);
        evens_total_temp -= evens[ei];
        evens_len_temp--;
        competitive_total = (competitive_total + ((evens[ei]+1)*(evens_total_temp+evens_len_temp))) % (1000000000);
        //printf("%ld\n", competitive_total);
    }
    return competitive_total;

}


int main() {
    long t;
    scanf("%ld", &t);
    for (long t_ = 0; t_ < t; t_++) {
        long n;
        scanf("%ld", &n);
        long s[n];
        for (long n_ = 0; n_ < n; n_++) {
            scanf("%ld", &s[n_]);
        }
        printf("FINAL : %ld", competitive_catherine(s, n));
    }
}