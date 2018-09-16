#pragma warning ( disable : 4996 )
#include <stdio.h>

void Q_345_7() {
	int num;

	scanf("%d", &num);

	do
	{
		printf("%d", num % 10);
		num /= 10;
	} while (num > 0);

	puts("");
}