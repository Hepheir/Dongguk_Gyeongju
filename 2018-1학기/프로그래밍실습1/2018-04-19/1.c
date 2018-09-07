#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a;

	scanf("%d", &a);

	if (a == 0)
		printf("양의 X축");
	else if (a < 90)
		printf("제 1사분면");
	else if (a == 90)
		printf("양의 Y축");
	else if (a < 180)
		printf("제 2사분면");
	else if (a == 180)
		printf("음의 X축");
	else if (a < 270)
		printf("제 3사분면");
	else if (a == 270)
		printf("음의 Y축");
	else if (a < 360)
		printf("제 4사분면");
	else
		printf("양의 X축");

	return 0;
}