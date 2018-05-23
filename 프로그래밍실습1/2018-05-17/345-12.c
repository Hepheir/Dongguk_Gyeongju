#include <stdio.h>

int main(void) {
	int cel, fah;

	for (cel = -60; cel <= 140; cel += 20)
	{
		fah = (9.0 / 5.0) * cel + 32;
		printf("¼·¾¾¿Âµµ %3d´Â È­¾¾¿Âµµ·Î %3d\n", cel, fah);
	}

	return 0;
}