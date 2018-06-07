#include <stdio.h>

int main(void)
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 7; j >= i; j--)
            printf(" ");
        for (j = i; j > 0; j--)
            printf("%d", j);
        for (j = 0; j <= i; j++)
            printf("%d", j);
        for (j = i; j <= 7; j++)
            printf(" ");
        puts("");
    }

    return 0;
}