#include <stdio.h>

#define OVER_TAX_RATE 0.15

int main(void)
{
    int income,
        tax = 0;

    printf("종합소득 금액(만원): ");
    scanf("%d", &income);

    printf("종합소득 %d만원\n", income);
    if (income >= 1200)
    {
        printf("1천 200만원까지의 세금 72만원\n");
        tax += 72;
        income -= 1200;

        printf("1천 200만원을 초과하는 금액 ");
    }
    
    printf("%d만원에 대한 세금 %.0f만원(%d만원 x %.0f%%)\n", income, income * OVER_TAX_RATE, income, OVER_TAX_RATE * 100);
    tax += income * OVER_TAX_RATE;

    printf("총 %d만원\n", tax);

    return 0;
}