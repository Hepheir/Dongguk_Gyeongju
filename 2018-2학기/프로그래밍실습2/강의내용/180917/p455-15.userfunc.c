#include <stdio.h>

int factorial(int n) {
	int res = 1;
	for (int i = n; i > 0; i--)
		res *= i;

	return res;
}

int combination(int n, int r) {
	return factorial(n) / factorial(r) * factorial(n - r);
}

int main() {
	int pascal[10][10] = { 0 };

	int n, r;

	for (n = 0; n < 10; n++) {
		for (r = 0; r <= n; r++) {
			pascal[n][r] = combination(n, r);
			printf("%4d", pascal[n][r]);
		}
		puts("");
	}
	
	return 0;
}
