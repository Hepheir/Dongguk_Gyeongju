#include <stdio.h>

void Q_445_12() {
	int i, j;

	int table[5][5] = {
		{78,48,78,98, 0},
		{99,92,83,29, 0},
		{29,64,83,89, 0},
		{34,78,92,56, 0},
		{ 0, 0, 0, 0, 0}
	};

	//////////////// Calc ////////////////
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			table[i][4] += table[i][j];

	for (j = 0; j < 4; j++)
		for (i = 0; i < 4; i++)
		{
			table[4][j] += table[i][j];

			table[4][4] += table[i][j];
		}

	//////////////// Print ////////////////
	printf("\tA\tB\tC\tD\t열의 합\t(가장 오른쪽 아래는 총 합.)");
	puts("");

	for (i = 0; i < 4; i++)
	{
		printf("%d", i);

		for (j = 0; j < 5; j++)
			printf("\t%d", table[i][j]);

		puts("");
	}

	printf("행의 합");
	for (j = 0; j < 5; j++)
		printf("\t%d", table[i][j]);

	puts("");
}