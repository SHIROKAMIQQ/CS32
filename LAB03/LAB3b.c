#include "squares.h"
#include <stdlib.h>
#include <stdio.h>
struct node* BuildLinkedList(int* dataset, int length);
void PrintLinkedList(struct node* head);
void PrintList(int* arr, int length);
typedef long long int int64;
int binarysearch(int i, int j, int n){
    if (n == 4) return 1;
    while(j-i != 1) {
        int m = ((int64)i+(int64)j)/2;
        int64 msq = (int64)m * (int64)m;
        if (msq == (int64)n) {
            return 1;
        } else if (msq < (int64)n) {
            i = m;
        } else {
            j = m;
        }
    }
    return 0;
}
int psqr(int n) {
    if (n<0) return 0;
    if (n==0||n==1) return 1;
    return binarysearch(1, n/2, n);
}
int squares(struct node* head, int** res) {
    int s=0;
    struct node* current=head;
    while (current != NULL) {
        if(psqr(current->val)) s++;
        current = current->next;
    }
    *res=malloc(s*sizeof(int));
    current=head;
    int i=0;
    while(current != NULL){
        if(psqr(current->val)){
            (*res)[i]=current->val;
            i++;
        }
        current = current->next;
    }
    return s;
}

int main() {

    int D1[6] = {25,0,24,25,9,-3};
    struct node* L1 = BuildLinkedList(D1, 6);
    //PrintLinkedList(L1);
    int** res1 = malloc(sizeof(int*));
    //int** res1;
    int ret1 = squares(L1, res1);
    //printf("squares func done\n");
    printf("%d\n",ret1);
    printf("%d\n", psqr(9));
    //PrintList(*res1, ret1);
}