#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void) {
	int arr_1[4][3] = {
		{ 46,79,78 },
		{ 35,57,28 },
		{ 43,68,76 },
		{ 56,78,98 }
	};

	int arr_2[4][3] = {
		{ 78,35,99 },
		{ 85,82,34 },
		{ 58,69,29 },
		{ 34,59,35 }
	};

	puts("Че");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%3d ", arr_1[i][j] + arr_2[i][j]);
		puts("");
	}

	puts("Тї");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%3d ", arr_1[i][j] - arr_2[i][j]);
		puts("");
	}
		

	return 0;
}