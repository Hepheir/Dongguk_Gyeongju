// Report 8
/*
필수2,필수4
선택2,선택3
중요
*/

#include <stdio.h>

int main(void)
{
	int i, j, n;

	// 1 번

	puts("1 번");

	n = 4;

	for (i = 1; i <= n; i++)
	{
		for (j = i; j > 0; j--)
			printf("*");

		puts("");
	}

	// 2 번

	puts("2 번");

	n = 4;

	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
			printf(" ");

		for (j = i; j >= -i; j--)
			printf("*");

		puts("");
	}

	// 3 번

	puts("3 번");

	n = 4;

	for (i = n - 1; i >= 0; i--)
	{
		for (j = n - 1; j > i; j--)
			printf(" ");

		for (j = i; j >= -i; j--)
			printf("*");

		puts("");
	}

	// 4 번

	puts("4 번");

	n = 4;

	for (i = 1; i < n; i++) // 계단식 쌓기
	{
		for (j = 0; j < i; j++)
			printf("*");

		puts("");
	}

	for (i = n; i >= 1; i--) // 역 계단식 쌓기
	{
		for (j = 0; j < i; j++)
			printf("*");

		puts("");
	}

	// 5 번

	puts("5 번");

	n = 4;

	for (i = 1; i < n; i++) // 계단식 쌓기
	{
		for (j = n; j > i; j--)
			printf(" ");

		for (j = i; j >= 1; j--)
			printf("*");

		puts("");
	}

	for (i = n; i >= 1; i--) // 역 계단식 쌓기
	{
		for (j = n; j > i; j--)
			printf(" ");

		for (j = i; j >= 1; j--)
			printf("*");

		puts("");
	}

	// 344 페이지 6번?

	puts("344 페이지 6 번");

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