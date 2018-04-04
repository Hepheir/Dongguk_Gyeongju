// CRT SECURE WARNIG

#include <stdio.h>

int main(void)
{
    float a, b, sqr, tri;

    printf("두 실수를 입력해주세요: ");
    scanf("%f %f", &a, &b);

    sqr = a * b;
    tri = a * b / 2;

    printf("가로가 %f, 세로가 %f인...\n", a, b);
    printf("사각형의 면적: %12.3f\n", sqr);
    printf("삼각형의 면적: %-12.3f\n", tri);

    return 0;
}