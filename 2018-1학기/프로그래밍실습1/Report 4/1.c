#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int a, b, m;

    printf("두 정수를 입력: ");
    scanf("%d%d", &a, &b);

    // b > a 이면 m에 b의 값을 넣음
    m = a < b ? b : a;
    // m == b일때, 즉, b > a 이면 b의 값에 a의 값을 넣음
    b = m == b ? a : b;
    // a에 a, b중 더 큰 값을 넣음
    a = m;


    printf("몫: %d\n", a / b);
    printf("나머지: %d\n", a % b);

    return 0;
}