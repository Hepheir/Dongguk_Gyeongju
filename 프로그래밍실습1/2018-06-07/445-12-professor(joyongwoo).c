#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void) {
	int col, row;
	int sum, total = 0;

	int arr[5][5] = {
		{ 78,48,78,98,0 },
		{ 99,92,83,29,0 },
		{ 29,64,83,89,0 },
		{ 34,78,92,56,0 },
		{ 0, 0, 0, 0, 0 }
	};

	// «‡¿« «’
	for (row = 0; row < 4;row++)
	{
		sum = 0;

		for (col = 0; col < 4; col++)
			arr[row][4] += arr[row][col];
	}
	
	// ø≠¿« «’
	for (col = 0; col < 4;col++)
	{
		sum = 0;

		for (row = 0; row < 4; row++)
		{
			arr[4][col] += arr[row][col];
		}
	}

	// √‚∑¬
	for (row = 0; row < 5; row++)
	{
		for (col = 0; col < 5; col++)
		{
			printf("%d\t", arr[row][col]);

			// √— «’
			total += arr[row][col];
		}
		puts("");
	}

	// √— «’
	printf("√— «’: %d\n", total);
	puts("");


	return 0;
}