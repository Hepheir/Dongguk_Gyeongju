#include <stdio.h>

int intpow(int, int);

int main(void) {
    int m, n;

    scanf("%d %d", &m, &n);
    
    printf("%d\n", intpow(m, n));
    return 0;
}

int intpow(int m, int n) {
    int res = 1;

    for (int i = 2; i <= n; i++)
        res *= m;
    
    return res;
}