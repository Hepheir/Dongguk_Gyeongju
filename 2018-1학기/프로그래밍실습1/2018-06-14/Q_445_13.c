#pragma warning (disable : 4996)
#include <stdio.h>

void Q_445_13() {
	int A[4][3] = {
		{ 46,79,78 },
		{ 35,57,28 },
		{ 43,68,76 },
		{ 56,78,98 }
	};
	int B[4][3] = {
		{ 78,35,99 },
		{ 85,82,34 },
		{ 58,69,29 },
		{ 34,59,35 }
	};

	//////////////// PRINT ////////////////

	//=//=//=//  ADD  //=//=//=//
	puts("행렬 A와 B의 합");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++)
			printf(" %3d", A[i][j] + B[i][j]);

		puts("");
	}
	puts("");

	//=//=//=// SUB //=//=//=//
	puts("행렬 A와 B의 차");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++)
			printf(" %3d", A[i][j] - B[i][j]);

		puts("");
	}
	puts("");
}