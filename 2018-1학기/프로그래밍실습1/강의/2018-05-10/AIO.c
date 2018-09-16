#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 1부터 100까지의 합
int sum_for(void)
{
	int sum = 0;

	for (int i = 1; i <= 100; i++)
		sum += i;

	printf("1 + 2 + ... + 100 = %d\n", sum);

	return 0;
}

int sum_while(void)
{
	int i = 1, sum = 0;

	while (i <= 100)
		sum += i++;

	printf("1 + 2 + ... + 100 = %d\n", sum);

	return 0;
}

int sum_dowhile(void)
{
	int i = 1, sum = 0;

	do
	{
		sum += i++;
	} while (i <= 100);

	printf("1 + 2 + ... + 100 = %d\n", sum);

	return 0;
}

// start ~ end 의 합
int startEnd_for(void)
{
	int start, end, sum = 0;

	printf("start와 end의 값을 입력: ");
	scanf("%d %d", &start, &end);

	for (int i = start; i <= end; i++)
		sum += i;

	printf("%d부터 %d까지의 합: %d\n", start, end, sum);

	return 0;
}

int startEnd_while(void)
{
	int start, end, sum = 0;

	printf("start와 end의 값을 입력: ");
	scanf("%d %d", &start, &end);

	int i = start;

	while (i <= end)
		sum += i++;

	printf("%d부터 %d까지의 합: %d\n", start, end, sum);

	return 0;
}

int startEnd_dowhile(void)
{
	int start, end, sum = 0;

	printf("start와 end의 값을 입력: ");
	scanf("%d %d", &start, &end);

	int i = start;

	do
	{
		sum += i++;
	}
	while (i <= end);

	printf("%d부터 %d까지의 합: %d\n", start, end, sum);

	return 0;
}

// 344p 4번 문제
int prac4(void)
{
	int count = 0;

	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 != 0 &&
			i % 3 != 0 &&
			i % 5 != 0 &&
			i % 7 != 0)
		{
			printf(" %3d", i);
			count++;

			if (count == 10)
			{
				puts("");
				count = 0;
			}
		}
	}

	return 0;
}

// 345p 12번 문제
int prac12(void)
{
	float celsius, fahrenheit;

	for (celsius = -60; celsius <= 140; celsius += 20)
	{
		fahrenheit = (9.0 / 5.0) * celsius + 32;
		printf("%f")
	}

	return 0;
}

int main(void)
{
	sum_dowhile();

	return 0;
}