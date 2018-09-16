#include <stdio.h>

int main(void)
{
	int i, j;

	for (i = 2; i <= 9; i++)
	{
		printf("%d´Ü:\n", i);

		for (j = 1; j <= 9; j++)
			printf(" %d X %d = %d\n", i, j, i * j);

		puts("");
	}

	return 0;
}