#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int year, gan, ji;

	printf("�⵵�� �Է�: ");
	scanf("%d", &year);

	gan = (year + 6) % 10;
	ji = (year + 8) % 12;


	// 10�� ���
	if (gan == 0)
		printf("��");
	else if (gan == 1)
		printf("��");
	else if (gan == 2)
		printf("��");
	else if (gan == 3)
		printf("��");
	else if (gan == 4)
		printf("��");
	else if (gan == 5)
		printf("��");
	else if (gan == 6)
		printf("��");
	else if (gan == 7)
		printf("��");
	else if (gan == 8)
		printf("��");
	else if (gan == 9)
		printf("��");

	// 12�� ���
	if (ji == 0)
		printf("��");
	else if (ji == 1)
		printf("��");
	else if (ji == 2)
		printf("��");
	else if (ji == 3)
		printf("��");
	else if (ji == 4)
		printf("��");
	else if (ji == 5)
		printf("��");
	else if (ji == 6)
		printf("��");
	else if (ji == 7)
		printf("��");
	else if (ji == 8)
		printf("��");
	else if (ji == 9)
		printf("��");
	else if (ji == 10)
		printf("��");
	else if (ji == 11)
		printf("��");

	// ������ ���
	printf("��\n");

	return 0;
}