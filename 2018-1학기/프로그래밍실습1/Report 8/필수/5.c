#include <stdio.h>

int main(void) {
	int cel;
	float fah;

	for (cel = -60; cel <= 140; cel += 20)
	{
		fah = (9.0 / 5.0) * cel + 32;
		printf("�����µ� : %3d ==> ȭ���µ� : %3.2f\n", cel, fah);
	}

    puts("");

	return 0;
}