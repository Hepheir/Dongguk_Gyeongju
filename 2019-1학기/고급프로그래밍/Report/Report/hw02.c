#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hw02_1() {
	char alphabet;

	printf("�ϳ��� ������(alphabet)�� �Է�: ");
	scanf("%c", &alphabet);

	if ('A' <= alphabet && alphabet <= 'Z')
		alphabet -= 'A' - 'a';
	else if ('a' <= alphabet && alphabet <= 'z')
		alphabet -= 'a' - 'A';

	printf("��ȯ �� : %c\n", alphabet);
}

void hw02_2() {
	int itemNum, quantity, price;

	printf("ǰ���ȣ�� ������ �Է��ϼ��� : ");
	scanf("%d %d", &itemNum, &quantity);

	switch (itemNum) {
	case 1:
		printf("Monitor");
		price = 192000;
		break;
	case 2:
		printf("Hard Disk");
		price = 85000;
		break;
	case 3:
		printf("CPU");
		price = 156000;
		break;
	case 4:
		printf("Mother Board");
		price = 206000;
		break;
	case 5:
		printf("Keyboard");
		price = 28500;
		break;
	case 6:
		printf("mouse");
		price = 14000;
		break;
	default:
		printf("ERROR! - Wrong item number\n");
		price = 0;
	}

	printf(" *%d, %d(��)\n", quantity, price*quantity);
}

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

void hw02_4() {
	int sum;
	// (1)
	sum = 0;
	for (int n = 1; n <= 100; n++)
		for (int i = 1; i <= n; i++)
			sum += i;
	printf("1+(1+2)+(1+2+3)+(1+2+3+4)+...+(1+2+3+...+98+99+100) = %d\n", sum);
	// (2)
	sum = 0;
	for (int n = 1; n <= 97; n += 4)
		for (int i = 1; i <= n; i += 2)
			sum += i;
	printf("1+(1+3+5)+(1+3+5+7+9)+(1+3+5+7+9+11+13)+...+(1+3+5+7+...+97) = %d\n", sum);
	// (3)
	sum = 0;
	for (int n = 1; n <= 100; n += 4)
		for (int i = 2; i <= n; i += 2)
			sum += i;
	printf("(2+4)+(2+4+6+8)+(2+4+6+8+10+12)+...+(2+4+6+8+10+12+...+100) = %d\n", sum);
}

void hw02_5() {
	int age;
	char name[20];

	printf("���̿� �̸� �Է� : ");
	scanf_s("%d %s", &age, name, 20);

	printf(">>> %d�� %s�Դϴ�.\n", age, name);
}

void hw02_6() {
	int po2, po3; // product of 2 and 3
	po2 = 0; po3 = 0;

	for (int i = 1; i <= 100; i++) {
		if (i % 2 == 0) po2 += i;
		if (i % 3 == 0) po3 += i;
	}

	printf("2�� ����� �� : %d\n", po2);
	printf("3�� ����� �� : %d\n", po3);
	printf("2, 3�� ����� �յ��� ���� %d �Դϴ�.\n", po2 - po3);
}

void hw02_7() {
	int n1, n2;
	int sum;

	printf("�� ���� ���� �Է� : ");
	scanf("%d %d", &n1, &n2);

	sum = 0;
	for (int i = n1 + 1; i < n2; i++)
		sum += i;

	printf("%d�� %d ������ ���� �� (�� �� ����) : %d\n", n1, n2, sum);
}

// hw02-8
int prime(int number);

void hw02_8() {
	int isPrime;
	int sum;

	sum = 0;
	for (int i = 2; i <= 100; i++) {
		isPrime = prime(i);
		if (isPrime) {
			sum += isPrime;
			printf("%d�� �Ҽ��Դϴ�!\n", isPrime);
		}
	}
	printf(">>> %d\n", sum);
}

int prime(int number) {
	for (int i = 2; i < number; i++)
		if (number % i == 0)
			return 0;
	return number;
}