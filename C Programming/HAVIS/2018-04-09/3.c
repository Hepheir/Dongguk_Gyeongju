#include <stdio.h>

int main(void)
{
    int bill, M10, M5, M1, C5, C1;

    printf("얼마: ");
    scanf("%d", &bill);

    if (bill % 1000)
    {
        printf("입력은 최소 천원 단위로 입력\n");
        return 1;
    }

    M10  = bill / 100000;
    bill = bill % 100000;

    M5   = bill / 50000;
    bill = bill % 50000;

    M1   = bill / 10000;
    bill = bill % 10000;

    C5   = bill / 5000;
    bill = bill % 5000;

    C1   = bill / 1000;
    bill = bill % 1000;

    printf("10만원권 %d개, 5만원권 %d개, 1만원권 %d개, 5천원권 %d개, 1천원권 %d개\n", M10, M5, M1, C5, C1);

    return 0;
}