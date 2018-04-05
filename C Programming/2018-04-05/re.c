#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int a, b, c, comp1, comp2;

	printf("세 개의 정수 입력 >>> ");
	scanf("%d%d%d", &a, &b, &c);

	// (a , b), c 중 최댓값이 될 수 없는 것 하나 탈락
	comp1 = a > b ? a : b;

	// 남아있는 두 변수 중 큰 것이 최댓값
	comp2 = comp1 > c ? comp1 : c;

	printf("최대값: %d\n", comp2);

	return 0;
}