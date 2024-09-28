#include "tabulate.h"
#include <stdio.h>
#include <stdlib.h>

int get_string_length(const char* s) {
    int length = 0;
    for (int i = 0; s[i]; i++){
        length++;
    }
    return length;
}

int get_digits_length(int n) {
    int digits = 0;
    while (n != 0) {
        digits++;
        n /= 10;
    }
    return digits;
}

void tabulate_sep(int r, int c, char **headers, long long int **data, char sep){
    int* highest_characters = (int*)malloc((r+1)*sizeof(int)); //Highest character of an entry for that column.

    // Get highest_characters per column.
    for (int column = 0; column < c; column++) {
        
        highest_characters[column] = get_string_length(headers[column]);
        for (int row = 0; row < r; row++) {
            int d = get_digits_length(data[row][column]);
            highest_characters[column] = (d > highest_characters[column]) ? d : highest_characters[column];
        }

    }

    //STDOUT
    printf("%c", sep);
    // Print header row
    for (int column = 0; column < c; column++) {
        printf(" ");
        for (int spaces = 0; spaces < highest_characters[column] - get_string_length(headers[column]); spaces++) {
            printf(" ");
        }
        printf("%s %c", headers[column], sep);
    }
    printf("\n");
    // Print data rows
    for (int row = 0; row < r; row++) {
        printf("%c", sep);
        for (int column = 0; column < c; column++) {
            printf(" ");
            for (int spaces = 0; spaces < highest_characters[column] - get_digits_length(data[row][column]); spaces++) {
                printf(" ");
            }
            printf("%lld %c", data[row][column], sep);
        }
        printf("\n");
    }

}

void tabulate(int r, int c, char **headers, long long int **data){
    tabulate_sep(r, c, headers, data, '|');
}

int main() {
    char** headers = (char**)malloc(40*sizeof(char*));
    for (int i = 0; i<40; i++) {
        headers[i] = (char*)malloc(18*sizeof(char));
    }
    headers[0] = "n";
    headers[1] = "fib(n)";
    headers[2] = "factorial(n)";

    long long int** data = (long long int**)malloc(40*sizeof(long long int*));
    for (int i = 0; i < 40; i++) {
        data[i] = (long long int*)malloc(40*sizeof(long long int));
    }
    data[0] = (long long int*){0, 0, 1};
    data[1] = (long long int*){1, 1, 1};
    data[2] = (long long int*){2, 1, 2};
    data[3] = (long long int*){3, 2, 6};
    data[4] = (long long int*){4, 3, 24};
    data[5] = (long long int*){5, 5, 120};
    data[6] = (long long int*){6, 8, 720};
    data[7] = (long long int*){7, 13, 5040};
    data[8] = (long long int*){8, 21, 40320};
    data[9] = (long long int*){9, 34, 362880};
    data[10] = (long long int*){10, 55, 3628800};
    data[11] = (long long int*){11, 89, 39916800};
    data[12] = (long long int*){12, 144, 479001600};
    data[13] = (long long int*){13, 233, 6227020800LL};
    data[14] = (long long int*){14, 377, 87178291200LL};
    data[15] = (long long int*){15, 610, 1307674368000LL};

    tabulate(16, 3, headers, data);

}

