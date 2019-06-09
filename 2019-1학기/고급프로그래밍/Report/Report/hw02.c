#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hw02_1() {
	char alphabet;

	printf("하나의 영문자(alphabet)을 입력: ");
	scanf("%c", &alphabet);

	if ('A' <= alphabet && alphabet <= 'Z')
		alphabet -= 'A' - 'a';
	else if ('a' <= alphabet && alphabet <= 'z')
		alphabet -= 'a' - 'A';

	printf("변환 후 : %c\n", alphabet);
}

void hw02_2() {
	int itemNum, quantity, price;

	printf("품명번호와 수량을 입력하세요 : ");
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

	printf(" *%d, %d(원)\n", quantity, price*quantity);
}

void hw02_3() {
	int number;
	int digit;

	printf("세 자리 정수 입력 : ");
	scanf("%d", &number);

	printf(">>> ");
	for (int i = 100; i > 0; i /= 10) {
		digit = number / i;
		number %= i;
		switch (digit) {
		case 0:
			printf("영");
			break;
		case 1:
			printf("일");
			break;
		case 2:
			printf("이");
			break;
		case 3:
			printf("삼");
			break;
		case 4:
			printf("사");
			break;
		case 5:
			printf("오");
			break;
		case 6:
			printf("육");
			break;
		case 7:
			printf("칠");
			break;
		case 8:
			printf("팔");
			break;
		case 9:
			printf("구");
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

	printf("나이와 이름 입력 : ");
	scanf_s("%d %s", &age, name, 20);

	printf(">>> %d살 %s입니다.\n", age, name);
}

void hw02_6() {
	int po2, po3; // product of 2 and 3
	po2 = 0; po3 = 0;

	for (int i = 1; i <= 100; i++) {
		if (i % 2 == 0) po2 += i;
		if (i % 3 == 0) po3 += i;
	}

	printf("2의 배수의 합 : %d\n", po2);
	printf("3의 배수의 합 : %d\n", po3);
	printf("2, 3의 배수의 합들의 차는 %d 입니다.\n", po2 - po3);
}

void hw02_7() {
	int n1, n2;
	int sum;

	printf("두 개의 정수 입력 : ");
	scanf("%d %d", &n1, &n2);

	sum = 0;
	for (int i = n1 + 1; i < n2; i++)
		sum += i;

	printf("%d와 %d 사이의 값의 합 (두 수 제외) : %d\n", n1, n2, sum);
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
			printf("%d는 소수입니다!\n", isPrime);
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