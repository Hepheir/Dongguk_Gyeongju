#include <stdio.h>

void Q_344_5() {
	int i, j, isPrime;

	for (i = 1; i <= 100; i++)
	{
		// 지금 검사하는 수가 소수인지를 나타내는 변수.
		isPrime = 1; // 1이면 참, 0이면 거짓.

		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				// 약수 중 1혹은 자기자신이 아닌 것이 있으면,
				// 그것은 소수가 아닙니다!
				if (j != 1 && j != i)
					isPrime = 0;
			}
		}

		if (isPrime)
			printf("% 3d", i);
	}
	puts("");
}