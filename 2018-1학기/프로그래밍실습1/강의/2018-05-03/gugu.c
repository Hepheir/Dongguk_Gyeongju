/*
Ű����� ���� 2���� ���� start, end�� �Է� �ް�
start���� end������ ���� ���ϴ� ���α׷� ����
*/

#include <stdio.h>

int main(void)
{
	puts("�������� ����!\n");

	for (int i = 1; i < 10; i++)
	{
		printf("%d��!\n", i);

		for (int j = 1; j < 10; j++)
			printf("%d X %d = %d\n", i, j, i * j);

		puts("");
	}

	return 0;
}