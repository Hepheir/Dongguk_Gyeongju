#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void) {
	int col, row;
	int sum, total = 0;

	int arr[4][4] = {
		{ 78,48,78,98 },
		{ 99,92,83,29 },
		{ 29,64,83,89 },
		{ 34,78,92,56 }
	};

	// 행의 합
	for (row = 0; row < 4;row++)
	{
		sum = 0;

		for (col = 0; col < 4; col++)
			sum += arr[row][col];

		printf("%d행의 합 : %d\n", row, sum);
	}
	puts("");
	
	// 열의 합
	for (col = 0; col < 4;col++)
	{
		sum = 0;

		for (row = 0; row < 4; row++)
		{
			sum += arr[row][col];
			total += arr[row][col];
		}

		printf("%d열의 합 : %d\n", col, sum);
	}
	puts("");

	// 총 합
	printf("총 합: %d\n", total);
	puts("");


	return 0;
}