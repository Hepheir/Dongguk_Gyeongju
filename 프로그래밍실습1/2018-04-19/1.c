#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a;

	scanf("%d", &a);

	if (a == 0)
		printf("���� X��");
	else if (a < 90)
		printf("�� 1��и�");
	else if (a == 90)
		printf("���� Y��");
	else if (a < 180)
		printf("�� 2��и�");
	else if (a == 180)
		printf("���� X��");
	else if (a < 270)
		printf("�� 3��и�");
	else if (a == 270)
		printf("���� Y��");
	else if (a < 360)
		printf("�� 4��и�");
	else
		printf("���� X��");

	return 0;
}