/*
�ʼ�

*1. ���� �迭�� �� ������ ���� ���� 10�� ������Ű�� ���α׷� ����
int data[] = { 1, 11, 111, 2, 22, 222, 3, 33, 333 };

*2. 444������ ���� 8��
���� ����: 1���� 10������ �� 20�� �Է�
+ �׷�������

*3. 445������ ���� 13��

����

*1. 444������ ���� 11�� (2���� �迭�� ����)

2. 445������ ���� 12�� (2���� �迭�� ����)

3. 445������ ���� 14��

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

	// 1�� ��� (�� ���)

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


	// 2�� ��� (�丸 ���)
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