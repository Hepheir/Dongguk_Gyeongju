#include <stdio.h>

int main(void)
{
	int count = 0;

	for (int i = 0; i <= 1000; i++)
	{
		if (i % 7 == 0)
			continue;

		printf(" %3d", i);
		count++;

		if (count % 9 != 0)
			continue;

		puts("");
	}

	puts("");

	return 0;
}


