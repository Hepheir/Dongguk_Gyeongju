#include <stdio.h>

<<<<<<< HEAD
int main(void)
{
    char gender;
    float height, weight, std_weight, bmi;

    printf("성별을 입력해주세요(남=M, 여=W): ");
    scanf("%c", &gender);

    printf("키(cm): ");
    scanf("%f", &height);

    printf("몸무게(kg): ");
    scanf("%f", &weight);


    if (gender == 'M' || gender == 'm')
        std_weight = (height / 100) * (height / 100) * 22;
    else if (gender == 'W' || gender == 'w')
        std_weight = (height / 100) * (height / 100) * 21;

    else {
        printf("<!> 알 수 없는 성별\ngender: %c\n", gender);
        return 1;
    }
    
    printf("신장 %.2fcm에서의 표준 체중: %.2fkg\n", height, std_weight);

    bmi = (weight - std_weight) / std_weight * 100;


    printf("\n당신은 ");

    if (bmi > 20)
        printf("비만");
    else if (bmi > 10)
        printf("체중 과다");
    else if (bmi > -10)
        printf("정상");
    
    else {
        printf("<!> 범위 밖 BMi\nBMI: %f\n", bmi);
        return 2;
    }

    printf("입니다.\n");
    
    printf("\nBMI: %f\n", bmi);

    return 0;
=======
int main()
{
    float a, b, c, d, e, f, g;

    printf("성별과 신장(키) 몸무게를 입력하여 주세요(남자=1, 여자=2): ");
    scanf("%f%f%f", &a, &b, &c);

    d = b * b * 22;
    e = b * b * 21;
    f = (c / d) * 100;
    g = (c / f) * 100;

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
>>>>>>> 40699bebacfefc26bf56a0b4439610a1193723a7
}