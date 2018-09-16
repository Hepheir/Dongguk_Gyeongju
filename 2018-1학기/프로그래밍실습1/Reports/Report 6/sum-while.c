// sum-while.c

#include <stdio.h>

int main(void)
{
    int start, end, sum = 0;

    printf("start와 end값을 입력: ");
    scanf("%d %d", &start, &end);

    int i = start;
    
    while (i <= end)
    {
        sum += i;
        i++;
    }

    printf("%d부터 %d까지의 합: %d\n", start, end, sum);
    return 0;
}