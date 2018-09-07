#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 5; j > i; j--)
			printf("%d", j);

		puts("");
	}

	return 0;
}