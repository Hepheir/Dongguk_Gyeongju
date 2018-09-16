#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int income,
		overInc,
		fee = 0;

	float tax = 0
		, taxRate;

	scanf("%d", &income);

	if (income > 30000) {
		fee = 9010;
		taxRate = .38f;

		overInc = income - 30000;

		printf("3억까지의 세금 %d만원 + ", fee);
		printf("3억을 초과하는 세금 %d만원에 대한 세금 %.0f만원", overInc, overInc * taxRate);
		printf("(%d만원 x %.2f%%)", overInc, taxRate * 100);

		tax += fee + overInc * taxRate;
	}
	else if (income > 8800) {
		fee = 1590;
		taxRate = .35f;

		overInc = income - 8800;

		printf("8천8백만원까지의 세금 %d만원 + ", fee);
		printf("8천8백만원을 초과하는 세금 %d만원에 대한 세금 %.0f만원", overInc, overInc * taxRate);
		printf("(%d만원 x %.2f%%)", overInc, taxRate * 100);

		tax += fee + overInc * taxRate;
	}
	else if (income > 4600) {
		fee = 582;
		taxRate = .24f;

		overInc = income - 4600;

		printf("4천6백만원까지의 세금 %d만원 + ", fee);
		printf("4천6백만원을 초과하는 세금 %d만원에 대한 세금 %.0f만원", overInc, overInc * taxRate);
		printf("(%d만원 x %.2f%%)", overInc, taxRate * 100);

		tax += fee + overInc * taxRate;
	}
	else if (income > 1200) {
		fee = 72;
		taxRate = .15f;

		overInc = income - 1200;

		printf("1천2백만원까지의 세금 %d만원 + ", fee);
		printf("1천2백만원을 초과하는 세금 %d만원에 대한 세금 %.0f만원", overInc, overInc * taxRate);
		printf("(%d만원 x %.2f%%)", overInc, taxRate * 100);

		tax += fee + overInc * taxRate;
	}
	else {
		fee = 0;
		taxRate = .06f;

		overInc = income;

		printf("%d만원에 대한 세금 %.0f만원", overInc, overInc * taxRate);
		printf("(%d만원 x %.2f%%)", overInc, taxRate * 100);

		tax += fee + overInc * taxRate;
	}

	printf("세금: %.0f만원\n", tax);

	return 0;
}