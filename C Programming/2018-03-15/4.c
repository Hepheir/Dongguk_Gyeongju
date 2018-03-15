/*
	2개의 정수 변수를 선언하고,
	각 변수에 임의의 값을 할당 한 후,
	두 개의 정수 변수의 합, 차, 곱, 나눗셈 결과를 출력하는 프로그램을 구현하시오.
	
	학번 2018212236
	이름 김동주

	Ver 1.0 2018-03-15
*/

#include <stdio.h>

// 운영체제가 호출하는 함수, 매개변수(없음)
int main(void) {
	int num1, num2;

	// 임의의 값을 할당
	num1 = 99;
	num2 = 18;

	printf("num1: %d\nnum2: %d\n\n", num1, num2);

	// 합
	printf("num1 + num2: %d\n", num1 + num2);

	// 차
	printf("num1 - num2: %d\n", num1 - num2);

	// 곱
	printf("num1 * num2: %d\n", num1 * num2);

	// 나눗셈
	printf("num1 / num2: %d\n", num1 / num2);

	// 나머지
	printf("num1 %% num2: %d\n", num1 % num2);

	
	return 0;
}