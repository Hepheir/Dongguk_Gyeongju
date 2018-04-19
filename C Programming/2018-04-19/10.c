#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int year;

	printf("년도를 입력: ");
	scanf("%d", &year);



	if (year % 400 == 0)
		printf("윤년");
	else if (year % 100 == 0)
		printf("평년");
	else if (year % 4 == 0)
		printf("윤년");




	if (year % 100 == 0 && year % 400 != 0)
		printf("평년");
	else if (year % 4 == 0)
		printf("윤년");


	printf("입니다.\n");

	return 0;
}
