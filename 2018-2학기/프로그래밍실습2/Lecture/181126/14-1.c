#include <stdio.h>

void increase(int origin, int increment);

int main(void)
{
    int amount = 10;
    increase(amount, 20);
    printf("%d\n", amount);

    return 0;
}

void increase(int origin, int increment)
{
    origin += increment;
}