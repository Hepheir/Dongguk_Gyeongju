/*
Report9
필수
3. 345-13
4. 5명 학생의 5개 교과목성적을 배열에 저장한후,
교과목별 총점, 평균과
학생별 총점, 평균
교과목별 최고, 최저 점수 및 학생 번호
학생별 총점 최고, 최저 점수 및 학생 번호
를 출력하는 프로그램

선택
1. 344-5
2. 345-7
3. 444-8
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define ARRAY_LENGTH 20

int main(void)
{
	int i;
	int data[20];
	int hist[10] = { 0 };
	int max = 0, max_num;

	for (i = 0; i < 20; i++)
	{
		scanf("%d", &data[i]);
		hist[data[i]]++;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d 는 %d 번\n", i, hist[i]);
	}

	for (i = 0; i < 10; i++)
	{
		if (max < hist[i])
		{
			max = hist[i];
			max_num = i;
		}
	}

	// 막대그래프
	puts("=====Graph====\n");
	for (i = 0; i < 10; i++)
	{
		printf("%2d : ", i);

		for (int j = 0; j < hist[i]; j++)
			printf("=");
		
		puts("");
	}

	printf("가장 많이 나온 수는 %d이고 %d번 나왔음\n", max_num, max);

	return 0;
}
