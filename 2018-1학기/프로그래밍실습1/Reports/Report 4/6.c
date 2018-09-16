#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int n;

    printf("정수인 천만 이하의 한 수를 입력: ");
    scanf("%d", &n);

    printf("%d만 ", n / 10000);
    n = n % 10000;

    printf("%d천 ", n / 1000);
    n = n % 1000;

    printf("%d백 ", n / 100);
    n = n % 100;

    printf("%d십 ", n / 10);
    n = n % 10;

    printf("%d입니다.\n ", n);

    return 0;
}