#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

long to_palindrome(char phrase[]) {
    int length = strlen(phrase);
    int left = 0, right = length - 1;
    long operations = 0;
    while (right > left) {
        //printf("%d%c %d%c\n", left, phrase[left], right, phrase[right]);
        if (phrase[left] == ' ') {
            left++;
        } else if (phrase[right] == ' ') {
            right--;
        } else {
            if (phrase[left] != phrase[right]) {
                operations++;
            }
            left++;
            right--;
        }
    }
    return operations;
}

void to_lower(char phrase[]) {
    for (long i = 0; phrase[i]; i++) {
        phrase[i] = tolower(phrase[i]);
        if (phrase[i] == '\n') {
            phrase[i] = '\0';
        }
    }
}

int main() {
  
    int t;
    scanf("%d", &t);
    getchar();
  
    for (int t_ = 0; t_ < t; t_++) {
        char phrase[200000];
        fgets(phrase, 200000, stdin);
        if (phrase[0] == '\n') {
            printf("%d\n", 0);
            continue;
        }
        to_lower(phrase);
        long operations = to_palindrome(phrase);
        printf("%ld\n", operations);
    }
  
}