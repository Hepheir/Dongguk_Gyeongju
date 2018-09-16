#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int year, gan, ji;

	printf("년도를 입력: ");
	scanf("%d", &year);

	gan = (year + 6) % 10; // 2017 % 10 == 7 , 정유 (정 == 3) , 7 >>> 3, 7 - 4 == 3,  7 + 6 == 13 >> 13 % 10 == 3
	ji = (year + 8) % 12;

	// 10간 출력
	switch (gan) {
	case 0:
		printf("갑");
		break;
	case 1:
		printf("을");
		break;
	case 2:
		printf("병");
		break;
	case 3:
		printf("정");
		break;
	case 4:
		printf("무");
		break;
	case 5:
		printf("기");
		break;
	case 6:
		printf("경");
		break;
	case 7:
		printf("신");
		break;
	case 8:
		printf("임");
		break;
	case 9:
		printf("계");
		break;
	}
		
	// 12간 출력
	switch (ji) {
	case 0:
		printf("자");
		break;
	case 1:
		printf("축");
		break;
	case 2:
		printf("인");
		break;
	case 3:
		printf("묘");
		break;
	case 4:
		printf("진");
		break;
	case 5:
		printf("사");
		break;
	case 6:
		printf("오");
		break;
	case 7:
		printf("미");
		break;
	case 8:
		printf("신");
		break;
	case 9:
		printf("유");
		break;
	case 10:
		printf("술");
		break;
	case 11:
		printf("해");
		break;
	}

	// 나머지 출력
	printf("년\n");

	return 0;
}
