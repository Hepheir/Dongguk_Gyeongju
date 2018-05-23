#include <stdio.h>

int main(void)
{
	int count = 0;

	for (int i = 0; i <= 1000; i++)
	{
		if (i % 7 == 0 || i % 11 == 0)
		{
			printf("%4d", i);
			count++;

			if (count % 9 == 0)
			{
				puts("");
				count = 0;
			}
			else
			{
				printf(" | ");
			}
		}
	}

	puts("");

	return 0;
}

