#include <stdio.h>

int main(void)
{
    int month;

    printf("몇 월 입니까?: ");
    scanf("%d", &month);

    if (month <= 0 || month > 12) {
        printf("<!> 유효하지 않은 입력\n");
        return 1;
    }

    printf("%d월은 ", month);

    if (month <= 3)
        printf("1");
    else if (month <= 6)
        printf("2");
    else if (month <= 9)
        printf("3");
    else
        printf("4");

    printf("사분기\n");

    return 0;
}