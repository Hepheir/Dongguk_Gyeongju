#include <stdio.h>

int main(void) {
	int n;

	// 13

	int sum = 0;

	for (n = 1; 1; n++)
	{
		sum += n;
		
		if (sum + (n + 1) > 10000)
			break;
	}

	printf("1���� n������ �� �߿��� 10000�� ���� �ʴ� ���� ū �� : %d\n", sum);
	printf("�׸��� �� ���� n : %d\n", n);


	puts("");

	// 14

	int mul = 1;

	for (n = 1; 1; n++)
	{
		mul *= n;

		if (mul * (n + 1) > 10000)
			break;
	}

	printf("1���� n������ �� �߿��� 10000�� ���� �ʴ� ���� ū �� : %d\n", mul);
	printf("�׸��� �� ���� n : %d\n", n);

	return 0;
}