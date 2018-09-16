#include <stdio.h>

int main(void)
{
	int i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (j + 1 < 5 - i)
				printf(" ");
			else
				printf("%d", 5 - j);
		}

		puts("");
	}

	return 0;
}