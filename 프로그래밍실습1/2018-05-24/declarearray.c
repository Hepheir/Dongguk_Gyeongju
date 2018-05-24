// Report 8
/*
필수2,필수4
선택2,선택3
중요
*/

#include <stdio.h>

#define SIZE 5

int main(void)
{
	// 배열 선언
	int score[SIZE];

	score[0] = 70;
	score[1] = 97;
	score[2] = 85;
	score[4] = 91;

	for (int i = 0; i < SIZE; i++)
		printf("%d   ", score[i]);
	puts("");

	return 0;
}