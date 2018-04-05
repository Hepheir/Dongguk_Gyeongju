#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int x = 5, y = 10;

	printf("두 정수를 입력>> ");
	scanf("%d%d", &x, &y);

	printf("The addition is: %d\n", x += y);
	printf("x = %d, y = %d\n", x, y);
	printf("The subtraction is: %d\n", x -= y);
	printf("x = %d, y = %d\n", x, y);
	printf("The multiplication is: %d\n", x *= y);
	printf("x = %d, y = %d\n", x, y);
	printf("The division is: %d\n", x /= y);
	printf("x = %d, y = %d\n", x, y);
	printf("The remainder is: %d\n", x %= y);
	printf("x = %d, y = %d\n", x, y);
	printf("x *= x + y is: %d\n", x *= x + y);
	printf("x = %d, y = %d\n", x, y);

	return 0;
}