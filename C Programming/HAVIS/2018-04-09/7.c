#include <stdio.h>

int main(void)
{
    char action;

    scanf("%c", &action);

    if (action == 'I')
    {
        int a, b;

        printf("2개의 정수를 16진수로 입력: ");
        scanf("%x%x", &a, &b);

        printf("A + B = %x (16진수)\n", a + b);
        printf("A - B = %d (10진수)\n", a - b);
        printf("A * B = %o  (8진수)\n", a * b);
    }
    else if (action == 'A')
    {
        int year, gan, ji;

        printf("년도를 입력: ");
        scanf("%d", &year);

        gan = (year - 2017) % 10;
        ji =  (year - 2017) % 12;

        // 양수로 통일
        gan = gan < 0 ? gan + 10 : gan;
        ji  = ji  < 0 ? ji  + 12 : ji;

        // 10간 출력
        if (gan == 0) {
            printf("정");
        } else
        if (gan == 1) {
            printf("무");
        } else
        if (gan == 2) {
            printf("기");
        } else
        if (gan == 3) {
            printf("경");
        } else
        if (gan == 4) {
            printf("신");
        } else
        if (gan == 5) {
            printf("임");
        } else
        if (gan == 6) {
            printf("계");
        } else
        if (gan == 7) {
            printf("갑");
        } else
        if (gan == 8) {
            printf("을");
        } else
        if (gan == 9) {
            printf("병");
        }

        // 12지 출력
        if (ji == 0) {
            printf("유");
        } else
        if (ji == 1) {
            printf("술");
        } else
        if (ji == 2) {
            printf("해");
        } else
        if (ji == 3) {
            printf("자");
        } else
        if (ji == 4) {
            printf("축");
        } else
        if (ji == 5) {
            printf("인");
        } else
        if (ji == 6) {
            printf("묘");
        } else
        if (ji == 7) {
            printf("진");
        } else
        if (ji == 8) {
            printf("사");
        } else
        if (ji == 9) {
            printf("오");
        } else
        if (ji == 10) {
            printf("미");
        } else
        if (ji == 11) {
            printf("신");
        }

        // 나머지 출력
        printf("년\n");

        return 0;
    }
}