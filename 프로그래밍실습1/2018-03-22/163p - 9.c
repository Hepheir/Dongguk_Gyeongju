#include <stdio.h>

#define PI 3.14

int main()
{
	float radius = 7.58;

	float space = PI * radius * radius
		, length = 2 * PI * radius;

	printf("������: %f\n", radius);
	printf("����: %f\n", space);
	printf("�ѷ�: %f\n", length);

	return 0;
}