#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b, c, comp1, comp2;

	printf("�� ���� ���� �Է� >>> ");
	scanf("%d%d%d", &a, &b, &c);

	// (a , b), c �� �ִ��� �� �� ���� �� �ϳ� Ż��
	comp1 = a > b ? a : b;

	// �����ִ� �� ���� �� ū ���� �ִ�
	comp2 = comp1 > c ? comp1 : c;

	printf("�ִ밪: %d\n", comp2);

	return 0;
}