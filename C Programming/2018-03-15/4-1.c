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
	int num1, num2;

	// ������ ���� �Ҵ�
	srand(time(NULL));

	num1 = rand();
	num2 = rand();


	printf("num1: %d\nnum2: %d\n\n", num1, num2);

	// ��
	int sum = num1 + num2;
	printf("num1 + num2: %d\n", sum);

	// ��
	int sub = num1 - num2;
	printf("num1 - num2: %d\n", sub);

	// ��
	int mul = num1 * num2;
	printf("num1 * num2: %d\n", mul);

	// ������
	int div = num1 / num2;
	printf("num1 / num2: %d\n", div);

	// ������
	int res = num1 % num2;
	printf("num1 %% num2: %d\n", res);

	
	return 0;
}