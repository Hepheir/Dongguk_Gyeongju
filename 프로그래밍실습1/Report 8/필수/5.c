#include <stdio.h>

int main(void) {
	int cel;
	float fah;

	for (cel = -60; cel <= 140; cel += 20)
	{
		fah = (9.0 / 5.0) * cel + 32;
		printf("¼·¾¾¿Âµµ : %3d ==> È­¾¾¿Âµµ : %3.2f\n", cel, fah);
	}

    puts("");

	return 0;
}