#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b, max, min;

	scanf("%d%d", &a, &b);

	max = (a > b) ? a : b;
	min = (a < b) ? a : b;

	printf("ū �� / ���� ��: %d\n", max / min);
	printf("ū �� % ���� ��: %d\n", max % min);

	return 0;
}