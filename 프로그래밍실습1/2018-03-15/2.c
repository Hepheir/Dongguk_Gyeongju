/*
	솔루션 / 프로젝트 / 소스파일: Ch03 / Prj02 / var.c
	C 프로그램의 기초를 다지기 위한 변수선언 이해
	V 1.0 2016.
*/
#include <stdio.h>

// 운영체제가 호출하는 함수, 매개변수(없음)
int main(void) {
	int snum;	//변수 선언
	int credits;

	snum = 20163021; // 값 지정
	credits = 18;

	printf("학번: %d\n", snum);
	printf("신청학점: %d\n", credits);
	
	return 0;
}