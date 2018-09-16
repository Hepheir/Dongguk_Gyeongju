#include <stdio.h>

#define MAX 5

int main(void) {
	int n = 1;

	while (n <= MAX)
		// 명령어가 하나만 있을 때는 중괄호가 없어도 된다.
		printf("%d\n", n++);
	

	printf("\n제어변수 count => %d\n", n);

	return 0;
}