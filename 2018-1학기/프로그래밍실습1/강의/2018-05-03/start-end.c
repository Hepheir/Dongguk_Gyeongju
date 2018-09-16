/*
	키보드로 부터 2개의 정수 start, end를 입력 받고
	start에서 end까지의 합을 구하는 프로그램 구현
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int start,
		end,
		result = 0;

	printf("2개의 정수를 입력(start, end): ");
	scanf("%d %d", &start, &end);

	for (int i = start; i <= end; i++) {
		result += i;
	}

	printf("%d부터 %d까지의 합은 %d\n", start, end, result);

	return 0;
}