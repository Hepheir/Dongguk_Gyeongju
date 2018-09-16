#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void) {
	int total;
	int arr[5][4] = {
		{ 97,90,88,95 },
		{ 76,89,75,83 },
		{ 60,70,88,82 },
		{ 83,89,92,85 },
		{ 75,73,72,78 }
	};

	puts("각 학생의 성적 합과 평균\n");
	for (int i = 0; i < 5;i++)
	{
		total = 0;

		for (int j = 0; j < 4; j++)
			total += arr[i][j];

		switch (i)
		{
			case 0: printf("이현수"); break;
			case 1: printf("김기수"); break;
			case 2: printf("김범용"); break;
			case 3: printf("장기태"); break;
			case 4: printf("이명수"); break;

			default: break;
		}
		printf(" 학생의 성적 총 합: %d, 평균 : %lf\n", total, (double)total / 3);
	}
	puts("");

	return 0;
}