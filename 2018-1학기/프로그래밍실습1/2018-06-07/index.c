/*
필수

*1. 다음 배열의 각 원소의 값을 각각 10배 증가시키는 프로그램 구현
int data[] = { 1, 11, 111, 2, 22, 222, 3, 33, 333 };

*2. 444페이지 문제 8번
문제 변경: 1에서 10까지의 수 20개 입력
+ 그래프까지

*3. 445페이지 문제 13번

선택

*1. 444페이지 문제 11번 (2차원 배열로 구현)

2. 445페이지 문제 12번 (2차원 배열로 구현)

3. 445페이지 문제 14번

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define M 2
#define N 3
#define P 2

int main(void) {

	int A[N][M] = {
		{ 3, 5 },
		{ 4, 2 },
		{ 5, 7 }
	};

	int B[P][N] = {
		{ 3, 8, 2 },
		{ 2, 4, 6 }
	};

	// 1번 방법 (식 출력)

	int cell;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cell = 0;

			printf("( ");
			for (int k = 0; k < M && k < P; k++)
			{
				printf("+ %d * %d ", A[i][k], B[k][j]);
				cell += A[i][k] * B[k][j];
			}
			printf(")");

			printf(" %d\t ", cell);
		}
		puts("");
	}


	puts("");


	// 2번 방법 (답만 출력)
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cell = 0;

			for (int k = 0; k < M && k < P; k++)
				cell += A[i][k] * B[k][j];

			printf("%d\t", cell);
		}
		puts("");
	}

	return 0;
}