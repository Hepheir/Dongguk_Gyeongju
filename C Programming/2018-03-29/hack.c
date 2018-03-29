#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int rndm, length, i, j;

	length = 64;

	for (i = 0; i < 200000000; i++)
	{
		for (j = 0; j < length; j++)
		{
			rndm = rand() % 26;
			printf("%c", 65 + rndm);
		}

		for (j = 0; j < length; j++)
			printf("\b", 65 + rndm);
	}

	return 0;
}