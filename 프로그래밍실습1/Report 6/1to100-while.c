#include <stdio.h>

int main(void)
{
    int sum = 0,
        i = 1;

    while (i <= 100)
    {
        sum += i;
        i++;
    }

    printf("1부터 100까지의 합: %d\n", sum);
    return 0;
}