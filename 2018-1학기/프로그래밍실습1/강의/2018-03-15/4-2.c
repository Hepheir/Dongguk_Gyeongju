/*
	2���� ���� ������ �����ϰ�,
	�� ������ ������ ���� �Ҵ� �� ��,
	�� ���� ���� ������ ��, ��, ��, ������ ����� ����ϴ� ���α׷��� �����Ͻÿ�.
	
	�й� 2018212236
	�̸� �赿��

	Ver 1.1 2018-03-15
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// �ü���� ȣ���ϴ� �Լ�, �Ű�����(����)
int main(void)
{
	float num1, num2;

	// ������ ���� �Ҵ�
	srand(time(NULL));

	num1 = (float)rand() / (float)rand();
	num2 = (float)rand() / (float)rand();


	printf("num1: %f\nnum2: %f\n\n", num1, num2);

	// ��
	float sum = num1 + num2;
	printf("num1 + num2: %f\n", sum);

	// ��
	float sub = num1 - num2;
	printf("num1 - num2: %f\n", sub);

	// ��
	float mul = num1 * num2;
	printf("num1 * num2: %f\n", mul);

	// ������
	float div = num1 / num2;
	printf("num1 / num2: %f\n", div);

/*
	# ������ ������ �Ϸ��� ������ ������ ����ؾ���.

	// ������
	int res = num1 % num2;
	printf("num1 %% num2: %d\n", res);

*/

	
	return 0;
}