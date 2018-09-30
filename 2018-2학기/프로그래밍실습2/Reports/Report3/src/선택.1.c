#include <stdio.h>

#define M 3
#define N 2
#define P 3

int main(void) {

	int A[M][N] = {
		{ 3, 5 },
		{ 4, 2 },
		{ 5, 7 }
	};

	int B[N][P] = {
		{ 3, 8, 2 },
		{ 2, 4, 6 }
	};

    int AB[M][P] = { 0 };

    int i, j, k;

	for (i = 0; i < M; i++) {
		for (j = 0; j < P; j++) {
			for (k = 0; k < M && k < P; k++)
				AB[i][j] += A[i][k] * B[k][j];

			printf("%d\t", AB[i][j]);
		}
		puts("");
	}

	return 0;
}