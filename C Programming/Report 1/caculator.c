/*
	2개의 실수변수에 값을 할당하고 4칙연산 결과를 출력하는 프로그램.
	
	학번 2018212236
	이름 김동주
	Ver 1.0 / 2018-03-19 / calculator.c
*/

#include <stdio.h>

int main(void)
{
    // 2개의 실수 변수 선언 후, 값을 할당.
    float n1, n2;

    n1 = 96.59875;
    n2 = 14.00712;


    printf("n1: %f\nn2: %f\n", n1, n2);

    // 합
    float n_sum = n1 + n2;
    printf("n1 + n2 = %f\n", n_sum);

    // 차
    float n_sub = n1 - n2;
    printf("n1 - n2 = %f\n", n_sub);

    // 곱
    float n_mul = n1 * n2;
    printf("n1 * n2 = %f\n", n_mul);

    // 분
    float n_div = n1 / n2;
    printf("n1 / n2 = %f\n", n_div);

    return 0;
}