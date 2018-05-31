#include <stdio.h>

#define ROWSIZE 4
#define COLSIZE 3

int main(void)
{
	int i, j;

	int score_1[ROWSIZE][COLSIZE] = {
		{ 46, 79, 78 },
		{ 35, 57, 28 },
		{ 43, 68, 76 },
		{ 56, 78, 98 }
	};
	int score_2[ROWSIZE][COLSIZE] = {
		{ 78, 35, 99 },
		{ 85, 82, 34 },
		{ 58, 69, 29 },
		{ 34, 59, 35 }
	};
	int score_3[ROWSIZE][COLSIZE];

	for (i = 0; i < ROWSIZE; i++)
		for (j = 0; j < COLSIZE; j++)
			score_3[i][j] = score_1[i][j] + score_2[i][j];

	for (i = 0; i < ROWSIZE; i++)
	{
		for (j = 0; j < COLSIZE; j++)
			printf("%6d", score_3[i][j]);
		printf("\n");
	}

	return 0;
}