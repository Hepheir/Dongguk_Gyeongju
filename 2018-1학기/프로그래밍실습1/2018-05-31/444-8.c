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

	int input;
	int count[10] = { 0 };

	int max_num = 0;
	
	for (i = 0; i <= ARRAY_LENGTH; i++)
	{
		printf("#%2d 0���� 9������ ���� �Է� : ", i);
		scanf("%d", &input);

		// �߸��� ���� �Է� ������ ��ȿó��.
		if (input > 9 || input < 0)
		{
			puts("��ȿ���� ���� �Է��Դϴ�.");
			i--;
			continue;
		}

		count[input]++;

		if (count[max_num] < count[input])
			max_num = input;
	}
	puts("");

	printf("���� ���� �Է� ���� �� : %d\n", max_num);
	printf("�� ���� �� �� : %d\n", count[max_num]);
	puts("");

	return 0;
}
