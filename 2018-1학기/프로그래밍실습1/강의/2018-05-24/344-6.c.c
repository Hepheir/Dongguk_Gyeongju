// Report 8
/*
필수2,필수4
선택2,선택3
중요
*/

#include <stdio.h>

int main(void)
{
	int i, j;

	for (i = 0; i < 8; i++)
	{

		for (j = 7; j > i; j--)
			printf(" ");

		for (j = i; j >= 0; j--)
			printf("%d", j);

		for (j = 1; j <= i; j++)
			printf("%d", j);

		puts("");
	}

	return 0;
}