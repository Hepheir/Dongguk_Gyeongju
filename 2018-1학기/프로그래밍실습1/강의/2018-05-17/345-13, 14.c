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

	printf("1부터 n까지의 합 중에서 10000을 넘지 않는 가장 큰 합 : %d\n", sum);
	printf("그리고 이 때의 n : %d\n", n);


	puts("");

	// 14

	int mul = 1;

	for (n = 1; 1; n++)
	{
		mul *= n;

		if (mul * (n + 1) > 10000)
			break;
	}

	printf("1부터 n까지의 곱 중에서 10000을 넘지 않는 가장 큰 곱 : %d\n", mul);
	printf("그리고 이 때의 n : %d\n", n);

	return 0;
}