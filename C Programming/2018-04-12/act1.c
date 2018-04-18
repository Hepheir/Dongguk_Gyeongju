#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int year, gan, ji;

	printf("년도를 입력: ");
	scanf("%d", &year);

	gan = (year + 6) % 10;
	ji = (year + 8) % 12;


	// 10간 출력
	if (gan == 0)
		printf("갑");
	else if (gan == 1)
		printf("을");
	else if (gan == 2)
		printf("병");
	else if (gan == 3)
		printf("정");
	else if (gan == 4)
		printf("무");
	else if (gan == 5)
		printf("기");
	else if (gan == 6)
		printf("경");
	else if (gan == 7)
		printf("신");
	else if (gan == 8)
		printf("임");
	else if (gan == 9)
		printf("계");

	// 12지 출력
	if (ji == 0)
		printf("자");
	else if (ji == 1)
		printf("축");
	else if (ji == 2)
		printf("인");
	else if (ji == 3)
		printf("묘");
	else if (ji == 4)
		printf("진");
	else if (ji == 5)
		printf("사");
	else if (ji == 6)
		printf("오");
	else if (ji == 7)
		printf("미");
	else if (ji == 8)
		printf("신");
	else if (ji == 9)
		printf("유");
	else if (ji == 10)
		printf("술");
	else if (ji == 11)
		printf("해");

	// 나머지 출력
	printf("년\n");

	return 0;
}