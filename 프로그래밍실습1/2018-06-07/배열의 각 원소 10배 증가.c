#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int data[] = { 1, 11, 111, 2, 22, 222, 3, 33, 333 };

	for (int i = 0; i < 9; i++)
	{
		data[i] *= 10;

		printf("%4d\n", data[i]);
	}

	return 0;
}