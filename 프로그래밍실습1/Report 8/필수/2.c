#include <stdio.h>

int main(void)
{
	int i, j, start, end;

    puts("구구단을 출력하겠다.");
    printf("지금 바로 start, end를 입력: ");
    scanf("%d %d", &start, &end);

	for (i = start; i <= end; i++)
	{
		printf("%d단:\n", i);

        // 그래도 구구단이므로 1~9까지만 곱합니다!
		for (j = 1; j <= 9; j++)
			printf(" %d X %d = %d\n", i, j, i * j);

		puts("");
	}

	return 0;
}