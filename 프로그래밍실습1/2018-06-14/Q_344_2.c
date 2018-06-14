#include <stdio.h>

void Q_344_2() {
	int i, j;

	for (i = 1; i <= 5; i++)
	{
		for (j = 5; j > i; j--)
			printf(" ");
		for (; j > 0; j--)
			printf("%d", j);

		puts("");
	}
}