#include <stdio.h>

int main(void)
{
    int count = 0;

    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 == 0) {
            printf("");
        }
        else if (i % 3 == 0) {
            printf("");
        }
        else if (i % 5 == 0) {
            printf("");
        }
        else if (i % 7 == 0) {
            printf("");
        }
        else
        {
            printf(" %3d", i);
            count++;

            if (count == 10)
            {
                puts(""); // line break
                count = 0;
            }
        }
    }

    return 0;
}