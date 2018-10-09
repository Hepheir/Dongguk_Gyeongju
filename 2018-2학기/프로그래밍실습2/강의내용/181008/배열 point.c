#include <stdio.h>

int main(void) {
    int i, sum = 0;
    int point[] = { 0 };
    int *address = point;
    int aryLength = sizeof (point) / sizeof (int);

    printf("Pos. of 'i' : %p\n", &i);
    printf("sizeof(i) : %lu\n", sizeof(&i));
    printf("sizeof(int *) : %lu\n", sizeof(int *));
    printf("sizeof(char *) : %lu\n", sizeof(char *));

    printf("point : %p\n", point);
    printf("point + 1 : %p\n", point + 1);
    printf("address : %p\n", address);
    printf("Pos. of 'address' : %p\n", &address);

    // 가능
    for (i = 0; i < aryLength; i++)
        sum += *(point + i);

    // 가능
    for (i = 0; i < aryLength; i++)
        sum += *(address++);

/*
    // 불가능 : point는 배열 이름, 상수이다.
    for (i = 0; i < aryLength; i++)
        sum += *(point++);

    // 변수 선언 : (메인) 메모리 할당
    // byte 수 중요

*/
}

