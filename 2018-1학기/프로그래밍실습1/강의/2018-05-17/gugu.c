#include <stdio.h>

#define N 9

int main(void)
{
	int i, j;

	for (i = 1; i <= N; i++)
	{
		printf("%d´Ü:\n", i);

		for (j = 1; j <= N; j++)
			printf(" %d X %d = %d\n", i, j, i * j);

		puts("");
	}

	return 0;
}