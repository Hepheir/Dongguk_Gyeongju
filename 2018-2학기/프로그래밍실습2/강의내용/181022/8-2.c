// file : pointer.c
#include <stdio.h>

int main(void)
{
    int data;
    printf("  data  %p  %8d\n", &data, data);

    int *ptrint;
    ptrint = &data;

    printf("변수명  주소값          저장값\n");
    printf("--------------------------------------\n");
    printf("  data  %p  %8d\n", &data, data);
    printf("ptrint  %p  %p\n", &ptrint, ptrint);
    printf("*ptrint                 %d\n", *(ptrint));
    *(ptrint) = 500;
    printf("*ptrint = 500           %d\n", *(ptrint));


// 간접참조 : `int *ptrint`에서 `int` 의 역할 :: *ptrint로 갔을 때, `int`가 있다는 뜻.
// char, int, double, pointer 자료형의 크기 중요, pointer에는 알맞은 자료형의 값을 가지는 주소가 들어가야함. (Lab 8-1 참조)
    return 0;
}