#include "friends.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tuple {
    int idx;
    int fs;
} tuple;
tuple* make_tuples(int n, int* f);
void merge_sort(tuple* arr, int left, int right);

void print_tuples(int n, tuple* t) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d), ", t[i].idx, t[i].fs);
    }
    printf("\n");
}

int main() {
    int n = 10;
    int f[10] = {3,2,5,6,2,5,1,7,4,2};
    tuple* t = make_tuples(n, f);
    print_tuples(n, t);
    merge_sort(t, 0, n-1);
    print_tuples(n, t);
}