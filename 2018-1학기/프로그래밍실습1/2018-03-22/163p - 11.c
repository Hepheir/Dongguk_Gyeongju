#include <stdio.h>

int main()
{
	float temperature;

	temperature = 10;
	printf("ȭ���µ� %f�� �����µ��� %f�Դϴ�.\n", temperature, 5.0 / 9.0 * (temperature - 32.0));

	temperature = 50;
	printf("ȭ���µ� %f�� �����µ��� %f�Դϴ�.\n", temperature, 5.0 / 9.0 * (temperature - 32.0));

	temperature = 80;
	printf("ȭ���µ� %f�� �����µ��� %f�Դϴ�.\n", temperature, 5.0 / 9.0 * (temperature - 32.0));

	temperature = 100;
	printf("ȭ���µ� %f�� �����µ��� %f�Դϴ�.\n", temperature, 5.0 / 9.0 * (temperature - 32.0));

	return 0;
}