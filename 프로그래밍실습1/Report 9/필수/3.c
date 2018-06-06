#include <stdio.h>


int main(void)
{
    int n;
    int sum = 0;

    for (n = 1; sum + n <= 10000; n++)
    {
        sum = sum + n;
    }

    printf("1부터 n까지의 합 중에서 10000을 넘지 않는 가장 큰 합 : %d\n", sum);
    printf("그 때의 n : %d\n", n);

    return 0;
}