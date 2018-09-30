#include <stdio.h>

#define SIZE 10

int main() {
	int pascal[SIZE][SIZE] = { 0 };

	int n, r;
	int f1, f2;

	for (n = 0; n < SIZE; n++) {
		for (r = 0; r <= n; r++) {
			// get Factorial.
			f1 = 1;
			for (int i = n; i > n - r; i--) // n ~ n - r + 1 ������ ���ϱ� (����) -- >f1
				f1 *= i;

			f2 = 1;
			for (int i = r; i > 0; i--) // r ~ 1 ���� ���ϱ� (�и�) --> f2
				f2 *= i;
			
			pascal[n][r] = f1 / f2; // ������ ���� : n!(r!(n-r)!) = f1 / f2

			printf("%4d", pascal[n][r]);
		}
		puts("");
	}

	return 0;
}