#include <stdio.h>

int main(void)
{
	int start, end, sum = 0;

	printf("2���� ���� (start, end)�� �Է�: ");
	scanf("%d %d", &start, &end);

	for (int i = end; i >= start; i--)
		sum += i;

	printf("%d���� %d������ ��: %d\n", end, start, sum);

	return 0;
}

