/*
	솔루션 / 프로젝트 / 소스파일: Ch03 / Prj04 / subtraction.c
	변수의 저장공간 자체와 변수에 저장된 값을 의미
	V 1.0 2016.
*/
#include <stdio.h>

// 운영체제가 호출하는 함수, 매개변수(없음)
int main(void) {
	int num1 = 30, num2 = 14;
	int difference;

	//대입 연산자의 왼쪽과 오른쪽에서의 변수의 의미 해석
	difference = num1 - num2;

	printf("num1: %d, num2: %d\n", num1, num2);
	printf("num1 - num2 의 결과: %d\n", difference);
	
	return 0;
}