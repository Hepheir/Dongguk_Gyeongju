#include <stdio.h>

int main() {
	int table[5][4] = {
		{ 97, 90, 88, 95 },
		{ 76, 89, 75, 83 },
		{ 60, 70, 88, 82 },
		{ 83, 89, 92, 85 },
		{ 75, 73, 72, 78 }
	};

	int i, j, sum;
	for (i = 0; i < 5; i++) {
		sum = 0;
		for (j = 0; j < 4; j++) {
			printf("%d\t", table[i][j]);
			sum += table[i][j];
		}
		printf("%d\t", sum);
		printf("%f\n", sum/(float)4);
	}

	system("pause");
	return 0;
}