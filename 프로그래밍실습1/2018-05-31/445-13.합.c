#include <stdio.h>

#define ROWSIZE 4
#define COLSIZE 3

int main(void)
{
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

	int r, c;

	for (r = 0; r < ROWSIZE; r++)
	{
		for (c = 0; c < COLSIZE; c++)
			printf(" %3d", score_1[r][c] + score_2[r][c]);
		puts("");
	}

	return 0;
}