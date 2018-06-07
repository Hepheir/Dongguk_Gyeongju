#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN 0
#define MAX 10

int main(void) {
	int input;
	int data[MAX - MIN + 1] = { 0 };

	int max = 0;

	for (int i = 0; i < 20; i++)
	{
		do
		{
			printf("#%d번째 숫자 입력(%d ~ %d): ", i, MIN, MAX);
			scanf("%d", &input);
		}
		while (input < MIN || input > MAX);

		data[input]++;

		if (data[max] < data[input])
			max = input;
	}

	printf("가장 많이 입력받은 수는 %d이고 그 빈도는 %d이다.\n", max, data[max]);

	return 0;
}