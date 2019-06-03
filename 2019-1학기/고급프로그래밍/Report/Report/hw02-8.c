#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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