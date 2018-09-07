#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    float x1, y1, x2, y2;

    x1 = 3.2;
    y1 = 4.6;

    x2 = -8.3;
    y2 = -2.3;

    printf("(X1, Y1)과 (X2, Y2)의 중간지점 = (%f, %f)\n", (x1 + x2) / 2.0, (y1 + y2) / 2.0);

    return 0;
}