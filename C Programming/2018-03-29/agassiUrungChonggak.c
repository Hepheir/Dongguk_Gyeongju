#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float a, b;

	printf("두 실수 A와 B를 입력해주세요.\n");

	printf("A: ");
	scanf("%f", &a);
	printf("B: ");
	scanf("%f", &b);

	printf("오우 놀 줄 아는 놈인가?~~\n");

	printf("A + B = %f\n", a + b);
	printf("A - B = %f\n", a - b);
	printf("A * B = %f\n", a * b);
	printf("A / B = %f\n", a / b);

	return 0;
}