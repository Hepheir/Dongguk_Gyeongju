#define _CRT_SECURE_NO_WARNINGS_

#include <stdio.h>
#include <stdlib.h>

#define HOR_SIZE 7
#define VER_SIZE 7

int printBigString(int length);

int main(void)
{
	/*
	int n = 6527;

	printf("%10d\n", n);
	printf("%010d\n", n);
	printf("%+010d\n", n);
	printf("%-10d\n", n);

	printf("%10o\n", n);
	printf("%010o\n", n);
	printf("%10x\n", n);
	printf("%#010x\n", n);

	// 9

	float a, b, square, tri;

	// scanf("%f", &a);
	// scanf("%f", &b);
	a = 4.423;
	b = 9.91;

	square = a * b;
	tri = a * b * 1 / 2;

	printf("square: %f\n", square);
	printf("tri: %f\n", tri);
	*/

	printBigString(6);

	return 0;
}


int printBigString(int length)
{
	int printed_words = 0;

	int pic[] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };

	// 세로
	for (int ver = 0; ver < VER_SIZE; ver++)
	{
		// 한 줄에 들어갈 문자 개수
		for (int len = printed_words; len < printed_words + length; len++)
		{
			// 가로
			for (int hor = 0; hor < HOR_SIZE; hor++)
			{
				// 문자 불러오기, 임시로 1출력
				if (pic[HOR_SIZE * ver + hor])
				{
					printf("#");
				}
				else {
					printf(" ");
				}
			}
			printf(" ");
		}
		printf("\n");
	}
	printed_words += length;
}
