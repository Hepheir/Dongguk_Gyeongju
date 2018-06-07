// do while

#include <stdio.h>

int main(void)
{
    int i = 100, sum = 0;

    do
    {
        sum += i;
        i--;
    }
    while (i >= 1);

    printf("100부터 1까지의 합: %d\n", sum);
    
    return 0;
}