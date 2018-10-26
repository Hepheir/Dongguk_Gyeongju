// p.441 Lab 9-4
// twoarysample.c

#include <stdio.h>

int main() {
    int abc[4][3] = {
        { 1, 2, 3 },
        { 5, 6, 7 },
        { 9, 10, 11 },
        { 13, 14, 15 }
    };
    int rowsize = sizeof(abc) / sizeof(*abc);
    int colsize = sizeof(*abc) / sizeof(int);

    printf("각 행의 첫 주소 출력: \n");
    for (int i = 0; i < rowsize; i++)
        printf("%p ", abc[i]);
    printf("\n\n");

    printf("2행 원소의 주소와 값 출력: \n");
    int *p = abc[1];
    for (int i = 0; i < colsize; i++)
    {
        printf("%p ", p);
        printf("%d\n", abc[1][i]);
    }

    return 0;
}