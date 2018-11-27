#include <stdio.h>
#include <string.h>

struct date
{
    int year;
    int month;
    int day;
};

struct account // sizeof account 는 36인 것으로 알고 있어도 됨.
{
    struct date open;
    char name[12];
    int actnum;
    double balance;
};

int main(void)
{
    struct account me = { { 2018, 3, 9 }, "홍길동", 1880, 300000 };

    printf("구조체크기 : %lu\n", sizeof(me));
    printf("[%d, %d, %d]\n", me.open.year, me.open.month, me.open.day);
    printf("%s %d %.2f\n", me.name, me.actnum, me.balance);
}