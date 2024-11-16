#include "task_order.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(int size, int* arr) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    printf("TEST CASE 1: ");
    int n1 = 9;
    int d1 = 7;
    dependency* deps1 = (dependency*)malloc(d1*sizeof(dependency));
    int task[8] = {0, 0, 0, 1, 1, 2, 2, 7};
    int prerequisite_task[8] = {5, 2, 1, 5, 3, 4, 6, 8};
    for (int i = 0; i < d1; i++) {
        deps1[i].task = task[i];
        deps1[i].prerequisite_task = prerequisite_task[i]; 
    }
    int* ret1 = find_task_order(n1, d1, deps1);
    print_list(n1, ret1);
    printf("\n");

    printf("TEST CASE 2: ");
    int n2 = 1;
    int d2 = 0;
    dependency* deps2 = (dependency*)malloc(d2*sizeof(dependency));
    int* ret2 = find_task_order(n2, d2, deps2);
    print_list(n2, ret2);
    printf("\n");


}