#include <stdio.h>

int main(void)
{
	int i, j, start, end;

    puts("�������� ����ϰڴ�.");
    printf("���� �ٷ� start, end�� �Է�: ");
    scanf("%d %d", &start, &end);

	for (i = start; i <= end; i++)
	{
		printf("%d��:\n", i);

        // �׷��� �������̹Ƿ� 1~9������ ���մϴ�!
		for (j = 1; j <= 9; j++)
			printf(" %d X %d = %d\n", i, j, i * j);

		puts("");
	}

	return 0;
}