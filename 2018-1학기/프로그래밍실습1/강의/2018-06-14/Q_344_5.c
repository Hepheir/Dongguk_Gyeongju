#include <stdio.h>

void Q_344_5() {
	int i, j, isPrime;

	for (i = 1; i <= 100; i++)
	{
		// ���� �˻��ϴ� ���� �Ҽ������� ��Ÿ���� ����.
		isPrime = 1; // 1�̸� ��, 0�̸� ����.

		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				// ��� �� 1Ȥ�� �ڱ��ڽ��� �ƴ� ���� ������,
				// �װ��� �Ҽ��� �ƴմϴ�!
				if (j != 1 && j != i)
					isPrime = 0;
			}
		}

		if (isPrime)
			printf("% 3d", i);
	}
	puts("");
}