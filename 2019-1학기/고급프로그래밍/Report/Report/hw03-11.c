#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int factorial(int x);
double bern(double p, int n, int x);

void hw03_11() {
	double p;
	int n;

	printf("������ Ȯ�� (0 < p < 1) : ");
	scanf("%lf", &p);
	printf("���� Ƚ�� (0 < n) : ");
	scanf("%d", &n);

	printf("��� 1�� ��� Ȯ�� : %.5lf\n",
		1 - bern(p, n, 0)
	);
	printf("���ƾ� 3�� ��� Ȯ�� : %.5lf\n",
		bern(p, n, 0)
		+ bern(p, n, 1)
		+ bern(p, n, 2)
		+ bern(p, n, 3)
	);
}

int factorial(int x) {
	if (x == 0)
		return 1;
	return x * factorial(x - 1);
}

double bern(double p, int n, int x) {
	double b = pow(p, x) * pow(1 - p, n - x);
	double nx = factorial(n) / (double)(factorial(x) * factorial(n - x));
	return b * nx;
}