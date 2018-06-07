// for

#include <stdio.h>

int main(void)
{
    int i, sum = 0;

    for (i = 100; i >= 1; i--)
        sum += i;

    printf("100부터 1까지의 합: %d\n", sum);
    
    return 0;
}