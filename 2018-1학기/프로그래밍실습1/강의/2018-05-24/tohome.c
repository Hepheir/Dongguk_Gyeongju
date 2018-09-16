// Report 8
/*
�ʼ�2,�ʼ�4
����2,����3
�߿�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STUDENTS 10

int main(void)
{
	double korScore[]  = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double engScore[]  = { 31, 42, 73, 42, 54, 56, 67, 87, 29, 10 };
	double mathScore[] = { 31, 52, 73, 84, 5, 6, 74, 85, 90, 100 };

	double korTotal  = 0;
	double engTotal  = 0;
	double mathTotal = 0;

	double personalTotal[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


	int i, j;

	// ����, ���κ� ���� �� ���ϱ�
	for (i = 0; i < STUDENTS; i++)
	{
		korTotal += korScore[i];
		personalTotal[i] += korScore[i];
	}

	for (i = 0; i < STUDENTS; i++)
	{
		engTotal += engScore[i];
		personalTotal[i] += engScore[i];
	}

	for (i = 0; i < STUDENTS; i++)
	{
		mathTotal += mathScore[i];
		personalTotal[i] += mathScore[i];
	}


	// ���� ����, ��� ���
	puts("===== ���� ���� & ��� =====");

	printf("����:\n", i);
	printf("  ���� : %lf\n", korTotal);
	printf("  ��� : %lf\n", korTotal / STUDENTS);
	puts("");

	printf("����:\n", i);
	printf("  ���� : %lf\n", engTotal);
	printf("  ��� : %lf\n", engTotal / STUDENTS);
	puts("");

	printf("����:\n", i);
	printf("  ���� : %lf\n", mathTotal);
	printf("  ��� : %lf\n", mathTotal / STUDENTS);
	puts("");

	// ���κ� ����, ��� ���
	puts("===== ���κ� ���� & ��� =====");

	puts("�л�  \t����\t����\t����\t����\t���");

	for (i = 0; i < STUDENTS; i++)
	{
		printf("�л�%2d", i + 1);
		printf("\t%.1lf", korScore[i]);
		printf("\t%.1lf", engScore[i]);
		printf("\t%.1lf", mathScore[i]);
		printf("\t%.1lf", personalTotal[i]);
		printf("\t%.1lf", personalTotal[i] / 3.0);
		puts("");
	}

	return 0;
}