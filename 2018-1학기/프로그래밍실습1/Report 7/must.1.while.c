// while

#include <stdio.h>

int main(void)
{
    int i = 100, sum = 0;

    while (i >= 1)
    {
        sum += i;
        i--;
    }

    printf("100부터 1까지의 합: %d\n", sum);
    
    return 0;
}