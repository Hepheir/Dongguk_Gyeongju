#include <stdio.h>

int main(void)
{
    int sum = 0,
        i = 1;

    do
    {
        sum += i;
        i++;
    }
    while (i <= 100);

    printf("1부터 100까지의 합: %d\n", sum);
    return 0;
}