/*
* 실수 2개의 값을 받아 4칙 연산 결과를 생성하는 함수 4개 정의하고,
* 정의된 4개의 함수를 이용하여 4칙 연산 결과를 생성하고 출력하는 프로그램 구현
*/

#include <stdio.h>

double sum(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double div(double a, double b) {
    return a / b;
}

int main(void) {
    int a = 3, b = 9;

    printf("a : %d, b : %d\n", a, b);

    printf("합 : %.2lf\n", sum(a, b));
    printf("차 : %.2lf\n", sub(a, b));
    printf("곱 : %.2lf\n", mul(a, b));
    printf("분 : %.2lf\n", div(a, b));

    return 0;
}