#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hw02_3() {
	int number;
	int digit;

	printf("�� �ڸ� ���� �Է� : ");
	scanf("%d", &number);

	printf(">>> ");
	for (int i = 100; i > 0; i /= 10) {
		digit = number / i;
		number %= i;
		switch (digit) {
		case 0:
			printf("��");
			break;
		case 1:
			printf("��");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("��");
			break;
		case 7:
			printf("ĥ");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
	}
	printf("\n");
}