// Report 8
/*
�ʼ�2,�ʼ�4
����2,����3
�߿�
*/

#include <stdio.h>

int main(void)
{
	int n, sum = 0;

	for (n = 1; sum + n <= 10000; n++)
	{
		sum += n;
	}
	n--;

	printf("1���� n������ �� �߿��� 10000�� ���� �ʴ� ���� ū �� : %d\n", sum);
	printf("�� ���� n�� �� : %d\n", n);

	return 0;
}