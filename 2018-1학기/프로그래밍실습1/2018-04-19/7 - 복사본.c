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

		printf("3������� ���� %d���� + ", fee);
		printf("3���� �ʰ��ϴ� ���� %d������ ���� ���� %.0f����", overInc, overInc * taxRate);
		printf("(%d���� x %.2f%%)", overInc, taxRate * 100);

		tax += fee + overInc * taxRate;
	}
	else if (income > 8800) {
		fee = 1590;
		taxRate = .35f;

		overInc = income - 8800;

		printf("8õ8�鸸�������� ���� %d���� + ", fee);
		printf("8õ8�鸸���� �ʰ��ϴ� ���� %d������ ���� ���� %.0f����", overInc, overInc * taxRate);
		printf("(%d���� x %.2f%%)", overInc, taxRate * 100);

		tax += fee + overInc * taxRate;
	}
	else if (income > 4600) {
		fee = 582;
		taxRate = .24f;

		overInc = income - 4600;

		printf("4õ6�鸸�������� ���� %d���� + ", fee);
		printf("4õ6�鸸���� �ʰ��ϴ� ���� %d������ ���� ���� %.0f����", overInc, overInc * taxRate);
		printf("(%d���� x %.2f%%)", overInc, taxRate * 100);

		tax += fee + overInc * taxRate;
	}
	else if (income > 1200) {
		fee = 72;
		taxRate = .15f;

		overInc = income - 1200;

		printf("1õ2�鸸�������� ���� %d���� + ", fee);
		printf("1õ2�鸸���� �ʰ��ϴ� ���� %d������ ���� ���� %.0f����", overInc, overInc * taxRate);
		printf("(%d���� x %.2f%%)", overInc, taxRate * 100);

		tax += fee + overInc * taxRate;
	}
	else {
		fee = 0;
		taxRate = .06f;

		overInc = income;

		printf("%d������ ���� ���� %.0f����", overInc, overInc * taxRate);
		printf("(%d���� x %.2f%%)", overInc, taxRate * 100);

		tax += fee + overInc * taxRate;
	}

	printf("����: %.0f����\n", tax);

	return 0;
}