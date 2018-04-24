#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    (n % 2) ? printf("%d\n", n * n * n) : printf("%d\n", n * n);

    return 0;
}