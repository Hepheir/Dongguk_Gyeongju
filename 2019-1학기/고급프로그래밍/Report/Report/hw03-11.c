#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int factorial(int x);
double bern(double p, int n, int x);

void hw03_11() {
	double p;
	int n;

	printf("성공할 확률 (0 < p < 1) : ");
	scanf("%lf", &p);
	printf("시행 횟수 (0 < n) : ");
	scanf("%d", &n);

	printf("적어도 1번 사고날 확률 : %.5lf\n",
		1 - bern(p, n, 0)
	);
	printf("많아야 3번 사고날 확률 : %.5lf\n",
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