#include <stdio.h>

#define PI 3.14

int main()
{
	float radius = 7.58;

	float space = PI * radius * radius
		, length = 2 * PI * radius;

	printf("반지름: %f\n", radius);
	printf("면적: %f\n", space);
	printf("둘레: %f\n", length);

	return 0;
}