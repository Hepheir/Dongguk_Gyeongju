// Report 8
/*
�ʼ�2,�ʼ�4
����2,����3
�߿�
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