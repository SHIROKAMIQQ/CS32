#include "inversions.h"
#include <stdlib.h>
#include <stdio.h>
void PrintList(long long int* arr, int length);
int64* Merge(int64* A, int lengthA, int64* B, int lengthB, int64* ret);
int64* MergeSort(int64* arr, int length, int64* ret);

int64* Merge(int64* A, int lengthA, int64* B, int lengthB, int64* ret) {
    int i = 0;
    int j = 0;
    int k = 0;
    int64 swaps = 0;
    int64* sorted_array = (int64*)malloc((lengthA+lengthB)*sizeof(int64));
    while (i < lengthA && j < lengthB) {
        if (A[i] <= B[j]) {
            sorted_array[k++] = A[i++];
            *ret += swaps;
        } else {
            sorted_array[k++] = B[j++];
            swaps++;
        }
    }
    while (j < lengthB) {
        sorted_array[k++] = B[j++];
    }
    while (i < lengthA) {
        sorted_array[k++] = A[i++];
        *ret += swaps;
    }
    return sorted_array;
}

int64* MergeSort(int64* arr, int length, int64* ret) {
    if (length == 1) {
        return arr;
    }

    int mid = (length-1)/2;
    int lengthA = mid+1;
    int lengthB = length-1-mid;
    int64* A = (int64*)malloc(lengthA*sizeof(int64));
    int k = 0;
    for (int i = 0; i < lengthA; i++) {
        A[i] = arr[k++];
    }
    int64* B = (int64*)malloc(lengthB*sizeof(int64));
    for (int i = 0; i < lengthB; i++){
        B[i] = arr[k++];
    }

    A = MergeSort(A, lengthA, ret);
    B = MergeSort(B, lengthB, ret);
    return Merge(A, lengthA, B, lengthB, ret);
}

int64 inversions(int n, int64* s){
    int64 ret = 0;
    int64* ptr = &ret;
    int64* sorted_array = MergeSort(s, n, ptr);
    PrintList(sorted_array, n);
    return ret;
}

int main() {
    int64 d1[7] = {3,1,4,1,5,9,2};
    int64 ret1 = inversions(7, d1);
    printf("%lld\n", ret1);

    int64 d2[7] = {1,2,3,4,5,6,7};
    int64 ret2 = inversions(6, d2);
    printf("%lld\n", ret2);

    int64 d3[3] = {3,2,1};
    int64 ret3 = inversions(3, d3);
    printf("%lld\n", ret3);
}