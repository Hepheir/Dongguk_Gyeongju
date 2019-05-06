#include <stdio.h>

float sumOfArray(int arr[4][7], int row, int col);
float avgOfArray(int arr[4][7], int row, int col);

void hw04_1() {
	char * dow[] = { "월", "화", "수", "목", "금", "토", "일" };
	int megawatts[4][7] = {
		{ 25, 30, 22, 28, 32, 45, 30 },
		{ 22, 25, 28, 26, 38, 40, 33 },
		{ 25, 34, 20, 22, 40, 36, 37 },
		{ 22, 28, 27, 28, 35, 40, 32 }
	};
	float sumAndAvg[4][2];

	int row, col;

	printf("구분");
	for (col = 0; col < 7; col++) {
		printf(" %5s", dow[col]);
	}
	printf(" %5s", "합계");
	printf(" %5s", "평균");
	printf("\n");


	for (row = 0; row < 4; row++) {
		printf("%d주:", row+1);
		for (col = 0; col < 7; col++) {
			printf(" %5d", megawatts[row][col]);
		}
		sumAndAvg[row][0] = sumOfArray(megawatts, row, -1);
		sumAndAvg[row][1] = avgOfArray(megawatts, row, -1);

		printf(" %5.0f", sumAndAvg[row][0]);
		printf(" %5.1f", sumAndAvg[row][1]);
		printf("\n");
	}

	printf("합계");
	for (col = 0; col < 7; col++) {
		printf(" %5.0f", sumOfArray(megawatts, -1, col));
	}

	printf("\n");

	printf("평균");
	for (col = 0; col < 7; col++) {
		printf(" %5.1f", avgOfArray(megawatts, -1, col));
	}
	printf("\n");
}

float sumOfArray(int arr[4][7], int row, int col) {
	float sum = 0;

	if (row >= 0) { // row selected
		for (int i = 0; i < 7; i++)
			sum += arr[row][i];
	}
	else { // col selected
		for (int i = 0; i < 4; i++)
			sum += arr[i][col];
	}

	return sum;
}

float avgOfArray(int arr[4][7], int row, int col) {
	float sum = sumOfArray(arr, row, col);
	
	if (row >= 0) {
		return sum / 4;
	}
	else {
		return sum / 7;
	}
}