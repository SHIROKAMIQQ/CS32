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

typedef struct ll_node{
    int val;
    struct ll_node* next;
}ll_node;

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

    ll_node** ll_pairs = (ll_node**)malloc(n*sizeof(ll_pairs));
    for (int i = 0; i < n; i++) {ll_pairs[i] = NULL;}
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = i+1;
        while (idxfs[i].fs > 0 && j < n){
            if (idxfs[j].fs > 0) {
                ll_node* newNode = (ll_node*)malloc(sizeof(ll_node));
                newNode->val = idxfs[j].idx;
                newNode->next = ll_pairs[idxfs[i].idx];
                ll_pairs[idxfs[i].idx] = newNode;
                (idxfs[j].fs)--;
                (idxfs[i].fs)--;
                count++;
            }
            j++;
        }
        merge_sort(idxfs, i+1, n-1);
    }

    friend_pair* pairs = (friend_pair*)malloc(count*sizeof(friend_pair));
    int fp = 0;
    for (int i = 0; i < n; i++) {
        if (idxfs[i].fs != 0) {
            count = -1;
            break;
        }
        while(ll_pairs[idxfs[i].idx] != NULL) {
            friend_pair newPair;
            newPair.person1 = idxfs[i].idx;
            newPair.person2 = ll_pairs[idxfs[i].idx]->val;
            pairs[fp++] = newPair;
            ll_pairs[idxfs[i].idx] = ll_pairs[idxfs[i].idx]->next;
        }
    }
    
    friends* ret = (friends*)malloc(sizeof(friends));
    ret->count = count;
    ret->pairs = pairs;
    return ret;
}