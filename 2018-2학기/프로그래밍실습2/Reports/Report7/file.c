#include <stdio.h>

void function(); // 함수 원형 선언
static int gValue; // 전역 변수

void main() {
    function();
    function();
    function();

    printf("main.sValue = %d \n", sValue);
}

void function() {
    static int sValue = 0;
    auto int aValue = 0;

    sValue = sValue + 3;
    aValue = aValue + 3;
    gValue = gValue + 3;

    printf("sValue = %d, aValue = %d \n", sValue, aValue);
    printf("gValue = %d \n", gValue);
}

char Arr2[] = { 'a', 'b', 'c' };
int ArrayLength = 3; // 에러