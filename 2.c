#include <stdio.h>

int main(void)
{
	int start, end, sum = 0;

	printf("2개의 정수 (start, end)를 입력: ");
	scanf("%d %d", &start, &end);

	for (int i = end; i >= start; i--)
		sum += i;

	printf("%d부터 %d까지의 합: %d\n", end, start, sum);

	return 0;
}

