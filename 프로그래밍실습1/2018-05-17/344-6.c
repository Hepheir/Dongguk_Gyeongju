#include <stdio.h>

int main(void) {
	int i, j;

	for (i = 0; i <= 7; i++)
	{
		for (j = 7; j > i; j--)
			printf(" ");

		for (j = i; j > 0; j--)
			printf("%d", j);

		for (j = 0; j <= i; j++)
			printf("%d", j);

		puts("");
	}

	return 0;
}