// Online C compiler to run C program online
#include <stdio.h>

int main() {
    char chars[] = {'a', '\0', 'b'};
    for (int i = 0; i < 3; i++){
        printf("%c", chars[i]);
    }

    return 0;
}