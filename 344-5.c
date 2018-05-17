#include <stdio.h>

int main(void)
{
	int i, j;

	for (i = 1; i <= 100; i++)
	{
		for (j = 2; j <= i; j++)
		{
			// for문을 한바퀴 다 돌 때까지 break;문을 지나지 않았으면 소수이다.
			if (j == i)
				printf("%d\n", j);

			if (i % j == 0)
				break;
		}
	}

	return 0;
}

