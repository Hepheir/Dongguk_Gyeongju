#include <stdio.h>

int main() {
    int area[3][3][3] = { 0 };

    int x, y, z;

    printf("0~2사이의 정수인 3차원 좌표를 입력 (x, y, z) : ");
    scanf("%d %d %d", &x, &y, &z);
    area[x][y][z] = 1;
    
    int i;
    for (z = 3; z > 0; z--) {
        for (y = 3; y > 0; y--) {
            // Indent
            for (i = 0; i < y; i++)
                printf("  ");

            for (x = 0; x < 3; x++) {
                if (area[x][y][z] == 1)
                    printf("#");
                else
                    printf("-");

                printf("        ");
            }

            printf("\n");
        }

        printf("\n");
    }
    
    return 0;
}