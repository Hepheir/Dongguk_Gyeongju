/*
Report9
�ʼ�
3. 345-13
4. 5�� �л��� 5�� ���������� �迭�� ��������,
������ ����, ��հ�
�л��� ����, ���
������ �ְ�, ���� ���� �� �л� ��ȣ
�л��� ���� �ְ�, ���� ���� �� �л� ��ȣ
�� ����ϴ� ���α׷�

����
1. 344-5
2. 345-7
3. 444-8
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	long int in;
	long int out;

	printf("�� �ڸ����� ������ ���� �Է�: ");
	scanf("%d", &in);
	
	int pos = 1;

	do
	{
		printf("%d", (in % (10 * pos)) / pos);
		pos *= 10;

	} while (in / pos);
	
	puts("");

	return 0;
}
