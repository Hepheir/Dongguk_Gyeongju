#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void) {
	float total;

	float arr[5][4] = {
		{ 97,90,88,95 },
		{ 76,89,75,83 },
		{ 60,70,88,82 },
		{ 83,89,92,85 },
		{ 75,73,72,78 }
	};

	printf("\t중간1\t중간2\t기말1\t기말2\t총점\t평균\n");
	for (int i = 0; i < 5;i++)
	{
		total = 0;

		// 이름
		switch (i)
		{
		case 0: printf("이현수"); break;
		case 1: printf("김기수"); break;
		case 2: printf("김범용"); break;
		case 3: printf("장기태"); break;
		case 4: printf("이명수"); break;

		default: break;
		}

		// 성적
		for (int j = 0; j < 4; j++)
		{
			printf("\t%.1lf", arr[i][j]);
			total += arr[i][j];
		}

		printf("\t%.1lf\t%.1lf\n", total, total / 3);
	}
	puts("");

	return 0;
}