#include "friends.h"
#include <stdlib.h>
#include <stdio.h>

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

void heap_push(int size, int i, tuple val, tuple* heap) {
    int parent = (i-1)/2;
    heap[i].idx = val.idx;
    heap[i].fs = val.fs;
    while ((parent >= 0 && parent <= i+1) &&
            val.fs > heap[parent].fs){
        heap[i].idx = heap[parent].idx;
        heap[i].fs = heap[parent].fs;
        heap[parent].idx = val.idx;
        heap[parent].fs = val.fs;
        i = parent;
        parent = (i-1)/2;
    } 
}

tuple* heapify(int* size, tuple* arr){
    tuple* heap = (tuple*)malloc((*size)*sizeof(tuple));
    for (int i = 0; i < (*size); i++) {
        heap_push((*size), i, arr[i], heap);
    }
    return heap;
}

void heap_pop(int* size, tuple* heap){
    (*size)--;
    heap[0].idx = heap[*size].idx;
    heap[0].fs = heap[*size].fs;
    
    int i = 0;
    int leftson = 2*i + 1;
    int rightson = 2*i + 2;
    while(leftson >= 0 && leftson < (*size)) {
        if (rightson >= 0 && rightson <= (*size)) {
            if (heap[leftson].fs > heap[rightson].fs) {
                if (heap[i].fs < heap[leftson].fs){
                    tuple temp;
                    temp.idx = heap[i].idx;
                    temp.fs = heap[i].fs;
                    heap[i].idx = heap[leftson].idx;
                    heap[i].fs = heap[leftson].fs;
                    heap[leftson].idx = temp.idx;
                    heap[leftson].fs = temp.fs;
                    i = leftson;
                    leftson = 2*i + 1;
                    rightson = 2*i + 2;
                } else {
                    break;
                }
            } else {
                if (heap[i].fs < heap[rightson].fs) {
                    tuple temp;
                    temp.idx = heap[i].idx;
                    temp.fs = heap[i].fs;
                    heap[i].idx = heap[rightson].idx;
                    heap[i].fs = heap[rightson].fs;
                    heap[rightson].idx = temp.idx;
                    heap[rightson].fs = temp.fs;
                    i = rightson;
                    leftson = 2*i + 1;
                    rightson = 2*i + 2;
                } else {
                    break;
                }
            }
        } else { 
            if (heap[i].fs < heap[leftson].fs) {
                tuple temp;
                temp.idx = heap[i].idx;
                temp.fs = heap[i].fs;
                heap[i].idx = heap[leftson].idx;
                heap[i].fs = heap[leftson].fs;
                heap[leftson].idx = temp.idx;
                heap[leftson].fs = temp.fs;
                i = leftson;
                leftson = 2*i + 1;
                rightson = 2*i + 2;
            } else {
                break;
            }
        }
    }
}

void printlist(int n, tuple* arr){
    for (int i = 0; i < n; i++) {
        printf("(%d, %d), ", arr[i].idx, arr[i].fs);
    }
    printf("\n");
}
void print_intlist(int n, int* arr) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void print_ll (int n, ll_node** ll) {
    for (int i = 0; i < n; i++) {
        ll_node* current = ll[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("%d ", current->val);
            current = current->next;
        }
        printf("\n");
    }
}

friends* guess_friends(int n, int* f) {
    tuple* idxfs = make_tuples(n, f);
    printf("TUPLE: ");printlist(n, idxfs);
    int size = n;
    tuple* heap = heapify(&size, idxfs);
    printf("HEAP: ");printlist(n, heap);
    free(idxfs);

    ll_node** ll_pairs = (ll_node**)malloc(n*sizeof(ll_pairs));
    for (int i = 0; i < n; i++) {ll_pairs[i] = NULL;}
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = 1;
        while (heap[0].fs > 0 && j < size){
            if (heap[j].fs > 0) {
                ll_node* newNode = (ll_node*)malloc(sizeof(ll_node));
                newNode->val = heap[j].idx;
                newNode->next = ll_pairs[heap[0].idx];
                ll_pairs[heap[0].idx] = newNode;
                (heap[j].fs)--;
                (heap[0].fs)--;
                f[heap[0].idx]--;
                f[heap[j].idx]--;
                count++;
            }
            j++;
        }
        heap_pop(&size, heap);
        printf("HEAP: "); printlist(size, heap);
    }

    printf("FINAL HEAP: "); printlist(n, heap);
    print_intlist(n, f);
    print_ll(n, ll_pairs);
    friend_pair* pairs = (friend_pair*)malloc(count*sizeof(friend_pair));
    int fp = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] != 0) {
            count = -1;
            break;
        }
        while(ll_pairs[i] != NULL) {
            friend_pair newPair;
            newPair.person1 = i;
            newPair.person2 = ll_pairs[i]->val;
            pairs[fp++] = newPair;
            ll_pairs[i] = ll_pairs[i]->next;
        }
    }
    
    friends* ret = (friends*)malloc(sizeof(friends));
    ret->count = count;
    ret->pairs = pairs;
    return ret;
}
