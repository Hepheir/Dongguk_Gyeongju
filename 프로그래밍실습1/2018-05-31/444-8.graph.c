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

#define ARRAY_LENGTH 20

int main(void)
{
	int i;
	int data[20];
	int hist[10] = { 0 };
	int max = 0, max_num;

	for (i = 0; i < 20; i++)
	{
		scanf("%d", &data[i]);
		hist[data[i]]++;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d �� %d ��\n", i, hist[i]);
	}

	for (i = 0; i < 10; i++)
	{
		if (max < hist[i])
		{
			max = hist[i];
			max_num = i;
		}
	}

	// ����׷���
	puts("=====Graph====\n");
	for (i = 0; i < 10; i++)
	{
		printf("%2d : ", i);

		for (int j = 0; j < hist[i]; j++)
			printf("=");
		
		puts("");
	}

	printf("���� ���� ���� ���� %d�̰� %d�� ������\n", max_num, max);

	return 0;
}
