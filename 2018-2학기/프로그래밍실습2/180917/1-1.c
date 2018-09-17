#include <stdio.h>
#define LB puts("")

int main() {

	int arr[4][4] = {
		{ 10, 20, 30, 40 },
		{ 10, 20, 30, 40 },
		{ 90, 10, 20, 30 },
		{ 40, 50, 60, 70 }
	};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d\t", arr[i][j]);
		}

		LB;
	}

	system("pause");
	return 0;
}