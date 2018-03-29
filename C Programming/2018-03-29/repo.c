#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b;

	printf("2개의 정수를 8진수로 입력하시오:\n");
	scanf("%o %o", &a, &b);

	printf("Calc\tDec\tOct\tHex\n");

	int _sum = a + b;
	printf("A+B\t%6d\t%6o\t%6x\n", _sum, _sum, _sum);

	int _sub = a - b;
	printf("A-B\t%6d\t%6o\t%6x\n", _sub, _sub, _sub);

	int _mul = a * b;
	printf("A*B\t%6d\t%6o\t%6x\n", _mul, _mul, _mul);

	int _div = a / b;
	printf("A/B\t%6d\t%6o\t%6x\n", _div, _div, _div);

	return 0;
}