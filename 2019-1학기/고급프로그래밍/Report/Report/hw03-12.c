#include <stdio.h>
void matSum3by3();
void matSub3by3();
void matMult3by3();

int A[3][3] = {
	{ 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 }
};

int B[3][3] = {
	{ 1, 0, 0 },
	{ 2, 1, 0 },
	{ 3, 2, 1 }
};

void hw03_12() {

	printf("A + B :\n");
	matSum3by3(A, B);

	printf("A - B :\n");
	matSub3by3(A, B);

	printf("A * B :\n");
	matMult3by3(A, B);

}

void matSum3by3() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf(" [%3d]", A[i][j] + B[i][j]);
		printf("\n");
	}
}

void matSub3by3() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf(" [%3d]", A[i][j] - B[i][j]);
		printf("\n");
	}
}

void matMult3by3() {
	int cell;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cell = 0;
			for (int k = 0; k < 3; k++) {
				cell += A[i][k] * B[k][j];
			}
			printf(" [%3d]", cell);
		}
		printf("\n");
	}
}