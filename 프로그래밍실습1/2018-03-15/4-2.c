/*
	2개의 정수 변수를 선언하고,
	각 변수에 임의의 값을 할당 한 후,
	두 개의 정수 변수의 합, 차, 곱, 나눗셈 결과를 출력하는 프로그램을 구현하시오.
	
	학번 2018212236
	이름 김동주

	Ver 1.1 2018-03-15
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 운영체제가 호출하는 함수, 매개변수(없음)
int main(void)
{
	float num1, num2;

	// 임의의 값을 할당
	srand(time(NULL));

	num1 = (float)rand() / (float)rand();
	num2 = (float)rand() / (float)rand();


	printf("num1: %f\nnum2: %f\n\n", num1, num2);

	// 합
	float sum = num1 + num2;
	printf("num1 + num2: %f\n", sum);

	// 차
	float sub = num1 - num2;
	printf("num1 - num2: %f\n", sub);

	// 곱
	float mul = num1 * num2;
	printf("num1 * num2: %f\n", mul);

	// 나눗셈
	float div = num1 / num2;
	printf("num1 / num2: %f\n", div);

/*
	# 나머지 연산을 하려면 정수형 변수를 사용해야함.

	// 나머지
	int res = num1 % num2;
	printf("num1 %% num2: %d\n", res);

*/

	
	return 0;
}