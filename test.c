#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("%ld\n", sizeof(int));
    printf("%ld\n", sizeof(bool));

    bool arr[10] = {false};
    arr[5] = true;
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}