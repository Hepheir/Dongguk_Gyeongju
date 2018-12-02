#include <stdio.h>
#include <string.h>

// 날짜를 위한 구조체
typedef struct date
{
    int year;   // 년
    int month;  // 월
    int day;    // 일
} DATE; // struct date를 DATE로도 표기

// 은행계좌를 위한 구조체
struct account
{
    DATE open;   // 계좌 개설일자
    char name[12];      // 계좌주 이름
    int actnum;         // 계좌번호
    double balance;     // 잔고
};

int main(void)
{
    struct account me = { {2018, 3, 9 }, "홍길동", 1001, 300000 };

    printf("구조체크기: %d\n", sizeof(me));
    printf("[%d, %d, %d]\n", me.open.year, me.open.month, me.open.day);
    printf("%s %d %.2f\n", me.name, me.actnum, me.balance);
}