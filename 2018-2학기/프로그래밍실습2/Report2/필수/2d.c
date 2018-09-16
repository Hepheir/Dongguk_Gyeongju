#include <stdio.h>

int main() {
    int table[2][3] = { 
        { 1, 2, 3 },
        { 4, 5, 6 }
    };

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++)
            printf("%d\t", table[row][col]);

        printf("\n");
    }

    return 0;
}