#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int bill;

	printf("정수인 천만 이하의 수를 입력: ");
	scanf("%d", &bill);

	printf("%d만 ", bill / 10000);

	bill = bill % 10000;
	printf("%d천 ", bill / 1000);

	bill = bill % 1000;
	printf("%d백 ", bill / 100);

	bill = bill % 100;
	printf("%d십 ", bill / 10);

	bill = bill % 10;
	printf("%d입니다.\n ", bill);

	return 0;
}