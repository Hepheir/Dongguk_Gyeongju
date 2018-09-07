// #define _CRT_SECURE_NO_WARNINGS_

#include <stdio.h>

int main(void)
{
    double km, mile;

    printf("길이를 km 단위로 입력해 주시오: ");
    scanf("%lf", &km);

    mile = 0.621371 * km;

    printf("입력받은 길이: %lf km 는 %lf mile 입니다.\n", km, mile);

    return 0;
}