#include <stdio.h>

int main(void)
{
	int theNumber = 65;

	printf("    8진수로는 %o\n", theNumber);
	printf("   16진수로는 %x\n", theNumber);
	printf("   10진수로는 %d\n", theNumber);
	printf("ASCII코드로는 %c\n", theNumber);

	return 0;
}