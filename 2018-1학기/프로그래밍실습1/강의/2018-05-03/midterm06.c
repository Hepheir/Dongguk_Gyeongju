#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int income, over;
	float tax = 0;

	printf("���ռҵ� �ݾ� �Է�: ");
	scanf("%d", &income);

	if (income > 30000 * 10000) {
		over = income - 3000000000;
		tax += over * 0.5F;
		income -= over;
	}
	if (income > 8800 * 10000) {
		over = income - 88000000;
		tax += over * 0.4F;
		income -= over;
	}
	if (income > 4600 * 10000) {
		over = income - 46000000;
		tax += over * 0.3F;
		income -= over;
	}
	if (income > 1200 * 10000) {
		over = income - 12000000;
		tax += over * 0.2F;
		income -= over;
	}
	tax += income * 0.1F;

	printf("����: %f\n", tax);

	return 0;
}