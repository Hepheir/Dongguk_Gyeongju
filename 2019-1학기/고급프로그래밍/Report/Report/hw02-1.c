#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hw02_1() {
	char alphabet;

	printf("�ϳ��� ������(alphabet)�� �Է�: ");
	scanf("%c", &alphabet);

	if ('A' <= alphabet && alphabet <= 'Z')
		alphabet -= 'A' - 'a';
	else if ('a' <= alphabet && alphabet <= 'z')
		alphabet -= 'a' - 'A';

	printf("��ȯ �� : %c\n", alphabet);
}