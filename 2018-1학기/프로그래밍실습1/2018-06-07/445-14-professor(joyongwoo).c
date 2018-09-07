#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int a[3][2] = { {3,5}, {4,2},{5,7} };
	int b[2][3] = { {3,8,2},{2,4,6} };
	int c[3][3] = { 0 };

	int i, j, k;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 2; k++)
				c[i][j] += a[i][k] * b[k][j];

			printf("%d\t", c[i][j]);
		}
		puts("");
	}

	return 0;
}