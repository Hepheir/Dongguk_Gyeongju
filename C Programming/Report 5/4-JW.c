#include <stdio.h>

int main()
{
    float a, b, c, d, e, f, g;

    printf("성별과 신장(키) 몸무게를 입력하여 주세요(남자=1, 여자=2): ");
    scanf("%f%f%f", &a, &b, &c);

    // 표준 체중
    d = b * b * 22 / 10000;
    e = b * b * 21 / 10000;

    // BMI계산
    f = (c / d) * 100;
    g = (c / e) * 100;

    if(a == 1)
    {
        if (f > 20)
            printf("비만");
        else if (f > 10)
            printf("과체중");
        else if (f > -10)
            printf("정상");
    }
    if(a == 2)
    {
        if (g > 20)
            printf("비만");
        else if (g > 10)
            printf("과체중");
        else if (g > -10)
            printf("정상");
    }

    return 0;
}