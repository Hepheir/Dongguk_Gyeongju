#include <stdio.h>

int main(void)
{
	int i, j;

	for (i = 1; i <= 100; i++)
	{
		for (j = 2; j <= i; j++)
		{
			// for���� �ѹ��� �� �� ������ break;���� ������ �ʾ����� �Ҽ��̴�.
			if (j == i)
				printf("%d\n", j);

			if (i % j == 0)
				break;
		}
	}

	return 0;
}

