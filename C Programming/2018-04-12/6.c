#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int bill;

	printf("������ õ�� ������ ���� �Է�: ");
	scanf("%d", &bill);

	printf("%d�� ", bill / 10000);

	bill = bill % 10000;
	printf("%dõ ", bill / 1000);

	bill = bill % 1000;
	printf("%d�� ", bill / 100);

	bill = bill % 100;
	printf("%d�� ", bill / 10);

	bill = bill % 10;
	printf("%d�Դϴ�.\n ", bill);

	return 0;
}