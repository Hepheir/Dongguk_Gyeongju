#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int year;

	printf("�⵵�� �Է�: ");
	scanf("%d", &year);



	if (year % 400 == 0)
		printf("����");
	else if (year % 100 == 0)
		printf("���");
	else if (year % 4 == 0)
		printf("����");




	if (year % 100 == 0 && year % 400 != 0)
		printf("���");
	else if (year % 4 == 0)
		printf("����");


	printf("�Դϴ�.\n");

	return 0;
}
