#include <stdio.h>

int main(void)
{
    int start, end, sum = 0;

    printf("start와 end값을 입력: ");
    scanf("%d %d", &start, &end);
    
    for (int i = start; i <= end; i++)
        sum += i;

    printf("%d부터 %d까지의 합: %d\n", start, end, sum);
    return 0;
}