#include "friends.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tuple {
    int idx;
    int fs;
} tuple;

void print_friends(friends* f) {
    if (f->count == -1) {
        printf("IMPOSSIBLE\n");
        return;
    }
    for (int i = 0; i < f->count; i++){
        printf("(%d, %d), ", (f->pairs)[i].person1, (f->pairs)[i].person2);
    }
    printf("\n");
}

int main() {
    int n1 = 6;
    int f1[6] = {2,2,0,2,1,3};
    friends* friends1 = guess_friends(n1, f1);
    print_friends(friends1);

    int n2 = 3;
    int f2[3] = {0,2,2};
    friends* friends2 = guess_friends(n2, f2);
    print_friends(friends2);
}