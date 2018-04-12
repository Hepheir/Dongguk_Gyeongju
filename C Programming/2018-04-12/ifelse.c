#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int n;

	printf("а╓╪Ж ют╥б: ");
	scanf("%d", &n);

	if (n % 2)
		printf("х╕╪Ж");
	else
		printf("б╕╪Ж");

	printf("ют╢о╢ы.\n");

	(n % 2) ? printf("х╕╪Ж") : printf("б╕╪Ж");
	printf("ют╢о╢ы.\n");

	return 0;
}