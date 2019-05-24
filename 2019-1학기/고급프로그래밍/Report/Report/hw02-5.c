#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hw02_5() {
	int age;
	char name[20];

	printf("나이와 이름 입력 : ");
	scanf_s("%d %s", &age, name, 20);

	printf(">>> %d살 %s입니다.\n", age, name);
}