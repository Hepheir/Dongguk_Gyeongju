// Report 8
/*
�ʼ�2,�ʼ�4
����2,����3
�߿�
*/

#include <stdio.h>

int main(void)
{
	int i, j, n;

	// 1 ��

	puts("1 ��");

	n = 4;

	for (i = 1; i <= n; i++)
	{
		for (j = i; j > 0; j--)
			printf("*");

		puts("");
	}

	// 2 ��

	puts("2 ��");

	n = 4;

	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
			printf(" ");

		for (j = i; j >= -i; j--)
			printf("*");

		puts("");
	}

	// 3 ��

	puts("3 ��");

	n = 4;

	for (i = n - 1; i >= 0; i--)
	{
		for (j = n - 1; j > i; j--)
			printf(" ");

		for (j = i; j >= -i; j--)
			printf("*");

		puts("");
	}

	// 4 ��

	puts("4 ��");

	n = 4;

	for (i = 1; i < n; i++) // ��ܽ� �ױ�
	{
		for (j = 0; j < i; j++)
			printf("*");

		puts("");
	}

	for (i = n; i >= 1; i--) // �� ��ܽ� �ױ�
	{
		for (j = 0; j < i; j++)
			printf("*");

		puts("");
	}

	// 5 ��

	puts("5 ��");

	n = 4;

	for (i = 1; i < n; i++) // ��ܽ� �ױ�
	{
		for (j = n; j > i; j--)
			printf(" ");

		for (j = i; j >= 1; j--)
			printf("*");

		puts("");
	}

	for (i = n; i >= 1; i--) // �� ��ܽ� �ױ�
	{
		for (j = n; j > i; j--)
			printf(" ");

		for (j = i; j >= 1; j--)
			printf("*");

		puts("");
	}

	// 344 ������ 6��?

	puts("344 ������ 6 ��");

	int k, l;

	for (i = 0; i < 8; i++)
	{

		for (j = 7; j > i; j--)
			printf(" ");

		for (k = i; k >= 0; k--)
			printf("%d", k);

		for (l = 1; l <= i; l++)
			printf("%d", l);

		puts("");
	}

	return 0;
}