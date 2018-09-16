/*
키보드로 부터 2개의 정수 start, end를 입력 받고
start에서 end까지의 합을 구하는 프로그램 구현
*/

#include <stdio.h>

int main(void)
{
	puts("구구단을 외자!\n");

	for (int i = 1; i < 10; i++)
	{
		printf("%d단!\n", i);

		for (int j = 1; j < 10; j++)
			printf("%d X %d = %d\n", i, j, i * j);

		puts("");
	}

	return 0;
}