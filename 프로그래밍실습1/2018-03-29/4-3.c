#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int dec = 30, oct = 012, hex = 0x5E;
	printf("�� ���� ������ ���� ������ ���� �Է��ϼ���. \n");
	printf("������ - ������ - ��������\n");

	scanf("%d - %o - %x", &dec, &oct, &hex);
	printf("\n�Է��� ���� ������ �����ϴ�.\n");
	printf("%d - %o - %x\n", dec, oct, hex);
	printf("%d - %d - %x\n", dec, oct, hex);

	return 0;
}