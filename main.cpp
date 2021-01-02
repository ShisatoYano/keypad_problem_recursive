#include <stdio.h>

// left, up, right, down move from current location
int row[] = {0, 0, -1, 0, 1};
int col[] = {0, -1, 0, 1, 0};

// return count of numbers of length n
// starting from key position (i, j)
int get_count_util(char keypad[][3], int i, int j, int n)
{
    if (keypad == NULL || n <= 0) return 0;

    if (n == 1) return 1;

    int k = 0, move = 0, ro = 0, co = 0, total_count = 0;

    for (move = 0; move < 5; move++) {
        ro = i + row[move];
        co = j + col[move];
        if (ro >= 0 && ro <= 3 && co >= 0 && co <= 2 &&
            keypad[ro][co] != '*' && keypad[ro][co] != '#')
        {
            total_count += get_count_util(keypad, ro, co, n - 1);
        }
    }

    return total_count;
}

// return count of all possible numbers of length n
// in a given keypad
int get_count(char keypad[][3], int n)
{
    // base case
    if (keypad == NULL || n <= 0) return 0;
    if (n == 1) return 10;

    int i = 0, j = 0, total_count = 0;
    for (i = 0; i < 4; ++i) { // loop on low
        for (j = 0; j < 3; ++j) { // loop on column
            // process for 0 to 9 digits
            if (keypad[i][j] != '*' && keypad[i][j] != '#')
            {
                // get count when number is starting from key
                // position (i, j) and in count obtained so far
                total_count += get_count_util(keypad, i, j, n);
            }
        }
    }

    return total_count;
}

int main() {
    char keypad[4][3] = {{'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'},
                         {'*', '0', '#'}};

    printf("Count for numbers of length %d: %dn", 3, get_count(keypad, 3));

    return 0;
}
