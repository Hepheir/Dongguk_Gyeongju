/*
	Ű����� ���� 2���� ���� start, end�� �Է� �ް�
	start���� end������ ���� ���ϴ� ���α׷� ����
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int start,
		end,
		result = 0;

	printf("2���� ������ �Է�(start, end): ");
	scanf("%d %d", &start, &end);

	for (int i = start; i <= end; i++) {
		result += i;
	}

	printf("%d���� %d������ ���� %d\n", start, end, result);

	return 0;
}