// Report 8
/*
�ʼ�2,�ʼ�4
����2,����3
�߿�
*/

#include <stdio.h>

#define SIZE 5

int main(void)
{
	// �迭 ����
	int score[SIZE];

	score[0] = 70;
	score[1] = 97;
	score[2] = 85;
	score[4] = 91;

	for (int i = 0; i < SIZE; i++)
		printf("%d   ", score[i]);
	puts("");

	return 0;
}