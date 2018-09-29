#include <stdio.h>

int main(void) {
	int input;
	int data[10] = { 0 };

	int max = 0;

	for (int i = 0; i < 20; i++)
	{
		scanf("%d", &input);

		data[input]++;

		if (data[max] < data[input])
			max = input;
	}

	printf("가장 많이 입력받은 수는 %d이고 그 빈도는 %d이다.\n", max, data[max]);

	return 0;
}