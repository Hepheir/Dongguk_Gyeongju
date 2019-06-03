#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hw02_1() {
	char alphabet;

	printf("하나의 영문자(alphabet)을 입력: ");
	scanf("%c", &alphabet);

	if ('A' <= alphabet && alphabet <= 'Z')
		alphabet -= 'A' - 'a';
	else if ('a' <= alphabet && alphabet <= 'z')
		alphabet -= 'a' - 'A';

	printf("변환 후 : %c\n", alphabet);
}