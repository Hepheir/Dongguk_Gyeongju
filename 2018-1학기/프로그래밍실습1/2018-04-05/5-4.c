#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int m = 10, n = 5;
	int result;

	result = m++ + --n; // 10 + 4 >>> 11, 4
	printf("m=%d n=%d result=%d\n", m, n, result);

	result = ++m - n--; // 12 - 4 >>> 12, 3
	printf("m=%d n=%d result=%d\n", m, n, result);

	return 0;
}