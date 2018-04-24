#include <stdio.h>

int main()
{
	float temperature;

	temperature = 10;
	printf("È­¾¾¿Âµµ %f´Â ¼·¾¾¿Âµµ·Î %fÀÔ´Ï´Ù.\n", temperature, 5.0 / 9.0 * (temperature - 32.0));

	temperature = 50;
	printf("È­¾¾¿Âµµ %f´Â ¼·¾¾¿Âµµ·Î %fÀÔ´Ï´Ù.\n", temperature, 5.0 / 9.0 * (temperature - 32.0));

	temperature = 80;
	printf("È­¾¾¿Âµµ %f´Â ¼·¾¾¿Âµµ·Î %fÀÔ´Ï´Ù.\n", temperature, 5.0 / 9.0 * (temperature - 32.0));

	temperature = 100;
	printf("È­¾¾¿Âµµ %f´Â ¼·¾¾¿Âµµ·Î %fÀÔ´Ï´Ù.\n", temperature, 5.0 / 9.0 * (temperature - 32.0));

	return 0;
}