#include "friends.h"
#include <stdlib.h>


typedef struct tuple {
    int idx;
    int fs;
} tuple;

tuple* make_tuples(int n, int* f) {
    tuple* ret = (tuple*)malloc(n*sizeof(tuple));
    for (int i = 0; i < n; i++) {
        ret[i].idx = i;
        ret[i].fs = f[i];
    }
    return ret;
}

void merge(tuple* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    tuple* leftArr = (tuple*)malloc(n1*sizeof(tuple));
    tuple* rightArr = (tuple*)malloc(n2*sizeof(tuple));
    for (int i = 0; i < n1; i++) {leftArr[i] = arr[left+i];}
    for (int j = 0; j < n2; j++) {rightArr[j] = arr[mid+1+j];}

    int i = 0; int j = 0; int k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].fs >= rightArr[j].fs) {arr[k++] = leftArr[i++];}
        else {arr[k++] = rightArr[j++];}
    }
    while (i < n1) {arr[k++] = leftArr[i++];}
    while (j < n2) {arr[k++] = rightArr[j++];}
}

void merge_sort(tuple* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

friends* guess_friends(int n, int* f) {
    tuple* idxfs = make_tuples(n, f);
    merge_sort(idxfs, 0, n-1);
}
