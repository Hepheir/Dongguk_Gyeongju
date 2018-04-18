#include <stdio.h>

int main(void)
{
    float angle;

    printf("각도를 입력(0~360): ");
    scanf("%f");

    if (angle == 0)
        printf("양의 X축\n");
    else if (angle < 90)
        printf("제 1사분면\n");
    else if (angle == 90)
        printf("양의 Y축\n");
    else if (angle < 180)
        printf("제 2사분면\n");
    else if (angle == 180)
        printf("음의의 X축\n");
    else if (angle < 270)
        printf("제 3사분면\n");
    else if (angle == 270)
        printf("음의 Y축\n");
    else if (angle < 360)
        printf("제 4사분면\n");
    else // 360일때
        printf("양의 X축\n");

    return 0;
}