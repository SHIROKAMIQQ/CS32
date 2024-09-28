#include <stdio.h>
#include <string.h>


int main() {
    int numbers[10];
    for (int i = 1; i <= 5; i++) {
        numbers[i-1] = i;
    }
    int count = 0;
    for (int j = 0; numbers[j]; j++) {
        count++;
        printf("%d\n", numbers[j]);
    }
    printf("COUNT%d\n", count);
}