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

	printf("���� ���� �Է¹��� ���� %d�̰� �� �󵵴� %d�̴�.\n", max, data[max]);

	return 0;
}