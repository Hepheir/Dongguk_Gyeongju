#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void) {
	int total;
	int arr[5][4] = {
		{ 97,90,88,95 },
		{ 76,89,75,83 },
		{ 60,70,88,82 },
		{ 83,89,92,85 },
		{ 75,73,72,78 }
	};

	puts("�� �л��� ���� �հ� ���\n");
	for (int i = 0; i < 5;i++)
	{
		total = 0;

		for (int j = 0; j < 4; j++)
			total += arr[i][j];

		switch (i)
		{
			case 0: printf("������"); break;
			case 1: printf("����"); break;
			case 2: printf("�����"); break;
			case 3: printf("�����"); break;
			case 4: printf("�̸��"); break;

			default: break;
		}
		printf(" �л��� ���� �� ��: %d, ��� : %lf\n", total, (double)total / 3);
	}
	puts("");

	return 0;
}