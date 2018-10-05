// 2번은 m^n을 구하는 함수 구현. 교재 표현 오류.

#include <stdio.h>

int intpow(int m, int n);

int main(void) {
    int m, n;

    printf("두 개의 임의 정수 m, n을 입력 : ");
    scanf("%d %d", &m, &n);
    
    printf("m^n : %d\n", intpow(m, n));

    return 0;
}

int intpow(int m, int n) {
    int res = 1;

    for (int i = 1; i <= n; i++)
        res *= m;
    
    return res;
}