#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float a, b;

	printf("�� �Ǽ� A�� B�� �Է����ּ���.\n");

	printf("A: ");
	scanf("%f", &a);
	printf("B: ");
	scanf("%f", &b);

	printf("���� �� �� �ƴ� ���ΰ�?~~\n");

	printf("A + B = %f\n", a + b);
	printf("A - B = %f\n", a - b);
	printf("A * B = %f\n", a * b);
	printf("A / B = %f\n", a / b);

	return 0;
}