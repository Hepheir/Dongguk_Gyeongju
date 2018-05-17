#include <stdio.h>

int main(void) {
	int i, j;

	for (i = 1; i <= 5; i++)
	{
		for (j = 5; j > i; j--)
			printf(" ");

		for (; j > 0; j--)
			printf("%d", j);

		puts("");
	}

	return 0;
}