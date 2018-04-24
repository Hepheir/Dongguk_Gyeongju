#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	printf("  1234567890\n");

	printf("1 %8d\n", 7629);
	printf("2 %-8d\n", 7629);
	printf("3 %10.3f\n", 32.369);
	printf("4 %10f\n", 32.369);
	printf("5 %5f\n", 32.369);
	printf("6 %-10.3f\n", 32.369);
	printf("7 %+10.3f\n", 32.369);
	printf("8 %-+10.3f\n", 32.369);

	int		n = 255;
	float	f = 3.141592F;

	printf("\n  1234567890\n");
	//여기서 포기

	return 0;
}