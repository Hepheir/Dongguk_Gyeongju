#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int income,
		overInc,
		fee = 0;

	float tax1
		, tax2
		, taxRate;

	scanf("%d", &income);

	if (income > 30000) {
		fee = 9010;
		taxRate = .38f;

		overInc = income - 30000;
	}
	else if (income > 8800) {
		fee = 1590;
		taxRate = .35f;

		overInc = income - 8800;
	}
	else if (income > 4600) {
		fee = 582;
		taxRate = .24f;

		overInc = income - 4600;
	}
	else if (income > 1200) {
		fee = 72;
		taxRate = .15f;

		overInc = income - 1200;
	}
	else {
		fee = 0;
		taxRate = .06f;

		overInc = income;
	}

	tax1 = fee + overInc * taxRate;
	tax2 = income * taxRate;

	printf("과세o: %.0f만원\n", tax1);
	printf("과세x: %.0f만원\n", tax2);

	return 0;
}