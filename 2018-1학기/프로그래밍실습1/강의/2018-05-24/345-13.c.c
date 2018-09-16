// Report 8
/*
필수2,필수4
선택2,선택3
중요
*/

#include <stdio.h>

int main(void)
{
	int n, sum = 0;

	for (n = 1; sum + n <= 10000; n++)
	{
		sum += n;
	}
	n--;

	printf("1부터 n까지의 합 중에서 10000을 넘지 않는 가장 큰 합 : %d\n", sum);
	printf("그 때의 n의 값 : %d\n", n);

	return 0;
}