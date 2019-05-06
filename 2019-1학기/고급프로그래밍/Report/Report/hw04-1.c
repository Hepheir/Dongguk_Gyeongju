#include <stdio.h>

#define ROW_SIZE 4
#define COL_SIZE 7

void hw04_1() {
	// Initiate
	char * dow[] = { "월", "화", "수", "목", "금", "토", "일" };
	int megawatts[ROW_SIZE][COL_SIZE] = {
		{ 25, 30, 22, 28, 32, 45, 30 },
		{ 22, 25, 28, 26, 38, 40, 33 },
		{ 25, 34, 20, 22, 40, 36, 37 },
		{ 22, 28, 27, 28, 35, 40, 32 }
	};

	// Supportive array.
	float chart[ROW_SIZE+2][COL_SIZE+2] = { 0 };

	int row, col;

	// Fill the chart
	//// Phase 1 : Copy data --> Calc sum of each rows --> Calc avg
	for (row = 0; row < ROW_SIZE; row++) {
		for (col = 0; col < COL_SIZE; col++) {
			chart[row][col] = megawatts[row][col]; // cpy
			chart[row][COL_SIZE] += chart[row][col]; // sum
		}
		chart[row][COL_SIZE+1] = chart[row][COL_SIZE] / COL_SIZE; // avg
	}

	//// Phase 2 : Calc sum of each cols --> Calc avg
	for (col = 0; col < COL_SIZE + 2; col++) {
		for (row = 0; row < ROW_SIZE; row++)
			chart[ROW_SIZE][col] += chart[row][col]; // sum
		chart[ROW_SIZE+1][col] = chart[ROW_SIZE][col] / ROW_SIZE; // avg
	}

	// Print chart
	//// Title
	printf("구분\t");
	for (col = 0; col < COL_SIZE; col++)
		printf(" %5s", dow[col]);
	printf(" %6s %6s", "합계", "평균");
	printf("\n");

	//// Data
	for (row = 0; row < ROW_SIZE+2; row++) {
		////// Prefix
		if (row < ROW_SIZE)
			printf("%d주:\t", row + 1);
		else if (row == ROW_SIZE)
			printf("합계\t");
		else if (row == ROW_SIZE+1)
			printf("평균\t");

		////// Data
		for (col = 0; col < COL_SIZE; col++)
			printf(" %5.0f", chart[row][col]);
		for (col = COL_SIZE; col < COL_SIZE+2; col++)
			printf(" %6.1f", chart[row][col]);
		printf("\n");
	}
}