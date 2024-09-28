#include "tabulate.h"
#include <stdio.h>
#include <stdlib.h>

// For every column, S\\\\\\\\\\\\\\\\\\S| is the format.
// For every entry: 
// Initially, we will fill in all 18 possible characters of the collumn,
// either SPACE or an actual digit/character of the number/string
// While we put entries through the column, take note of the highest number of characters in an entry.
// Remember, actual characters in the entry are right aligned.
// 18 - 'highest_characters' will be the number of \0's starting from the left of the column.

int get_string_length(char* s) {
    int length = 0;
    for (int i = 0; s[i]; i++){
        length++;
    }
    return length;
}

void tabulate_sep(int r, int c, char **headers, int64 **data, char sep){
    char** table = (char**)malloc((r+1)*(c*21+1)*sizeof(char));
    char digit_map[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    //Fills column with a specific character
    void fill_column(int column, char spec) {
        for (int row = 0; row <= r; row++) {
            table[row][column] = spec;
        }
    }
    //Fills remaining characters in the cell with SPACE
    void fill_space(int row, int column, int remaining) {
        int start_index = (1 + 21*column) + 1;
        for (int i = 0; i < remaining; i++) {
            table[row][start_index+i] = ' ';
        }
    }
    //First character is always guaranteed to be 'sep'.
    fill_column(0, sep);
    
    for (int column = 0; column < c; column++) {

        //First sub character column is guaranteed to be SPACE
        int column_start = 1 + (21*column);
        fill_column(column_start, ' ');

        int highest_characters = 0;

        //Put header in first row
        char* header = headers[column];
        int header_length = get_string_length(header), remaining = 18 - header_length;
        highest_characters = header_length;
        for(int i = 0; i < header_length; i++) {
            table[0][(column_start+1)+(remaining)+i] = header[i];
            fill_space(0, column, remaining);
        }

        //For every row, input the corresponding data entry for that column
        for (int row = 0; row < r; row++) {
            long long int entry = data[row][column];
            int current_digits = 0, d;
            while (entry != 0) {
                table[row+1][(column_start+18)-current_digits++] = digit_map[entry%10];
                entry /= 10;
            }
            highest_characters = (current_digits > highest_characters) ? current_digits : highest_characters; 
            fill_space(row+1, column, 18-current_digits);
        }

        //Shrink completely empty subcolumns with '\0'
        for (int excess_index = 0; excess_index < 18 - highest_characters; excess_index++) {
            fill_column((column_start+1)+excess_index, '\0');
        }

    }

    //STDOUT
    for (int row = 0; row < r+1; row++) {
        for (int column = 0; column < c*21+1; column++) {
            printf("%c", table[row][column]);
        }
        printf("\n");
    }

}

void tabulate(int r, int c, char **headers, int64 **data){
    tabulate_sep(r, c, headers, data, '|');
}

int main() {
    int64 data[][3] = {
        {0, 0, 1},
        {1, 1, 1},
        {2, 1, 2},
        {3, 2, 6},
        {4, 3, 24},
        {5, 5, 120},
        {6, 8, 720},
        {7, 13, 5040},
        {8, 21, 40320},
        {9, 34, 362880},
        {10, 55, 3628800},
        {11, 89, 39916800},
        {12, 144, 479001600},
        {13, 233, 6227020800LL},
        {14, 377, 87178291200LL},
        {15, 610, 1307674368000LL},
    };
    char headers[][18] = {"n", "fib(n)", "factorial(n)"};
    tabulate(16, 3, headers, data);
    printf("\n");
    tabulate_sep(16, 3, headers, data, '#');
}

/*
S\\\\\\\\\\\\\\\\\\S|
|S\\\\\\\\\\\\\\\\\\S|S\\\\\\\\\\\\\\\\\\S|
border is at 0, 21, 42, ...
by default, c0 is border; and then every col gives S\x18S|
*/