// Report 8
/*
필수2,필수4
선택2,선택3
중요
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

	// 과목별, 개인별 성적 합 구하기
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


	// 과목별 총점, 평균 출력
	puts("===== 과목별 총점 & 평균 =====");

	printf("국어:\n", i);
	printf("  총점 : %lf\n", korTotal);
	printf("  평균 : %lf\n", korTotal / STUDENTS);
	puts("");

	printf("영어:\n", i);
	printf("  총점 : %lf\n", engTotal);
	printf("  평균 : %lf\n", engTotal / STUDENTS);
	puts("");

	printf("수학:\n", i);
	printf("  총점 : %lf\n", mathTotal);
	printf("  평균 : %lf\n", mathTotal / STUDENTS);
	puts("");

	// 개인별 총점, 평균 출력
	puts("===== 개인별 총점 & 평균 =====");

	puts("학생  \t수학\t영어\t국어\t총점\t평균");

	for (i = 0; i < STUDENTS; i++)
	{
		printf("학생%2d", i + 1);
		printf("\t%.1lf", korScore[i]);
		printf("\t%.1lf", engScore[i]);
		printf("\t%.1lf", mathScore[i]);
		printf("\t%.1lf", personalTotal[i]);
		printf("\t%.1lf", personalTotal[i] / 3.0);
		puts("");
	}

	return 0;
}