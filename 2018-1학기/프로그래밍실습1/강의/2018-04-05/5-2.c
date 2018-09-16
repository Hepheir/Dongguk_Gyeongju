#define _CRT_SECURE_NO_WARNINGS_

#include <stdio.h>

int main(void)
{
	int a, b, c;
	a = b = c = 5;

	printf("a = a + 2 ==> %d\n", a = a + 2); //7
	printf("a ==> %d\n", a = b = c); // 5
	printf("a = b + c ==> %d\n", a = b + c); // 10
	printf("a ==> %d\n", a);

	return 0;
}