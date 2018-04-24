#include <stdio.h>

int main() {
	int i, sum = 0;

	for (i = 0; i <= 100; i++) {
		sum = sum + i;
	}
	printf("%d에서 %d까지의 합 = %d 입니다.\n", 1, 100, sum);

	return 0;
}