// for

#include <stdio.h>

int main(void)
{
	int i, sum = 0;

	for (i = 100; i >= 1; i--)
		sum += i;

	printf("100부터 1까지의 합: %d\n", sum);


// while

	i = 100, sum = 0;

	while (i >= 1)
	{
		sum += i;
		i--;
	}
	printf("100부터 1까지의 합: %d\n", sum);


// do while

	i = 100, sum = 0;

	do
	{
		sum += i;
		i--;
	}
	while (i >= 1);

	printf("100부터 1까지의 합: %d\n", sum);

	return 0;
}