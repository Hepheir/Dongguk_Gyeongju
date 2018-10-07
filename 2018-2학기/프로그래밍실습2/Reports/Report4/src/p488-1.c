#include <stdio.h>

float inchToCm(float);

int main(void)
{
    float inch;
    scanf("%f", &inch);

    printf("%f\n", inchToCm(inch));
    return 0;
}

float inchToCm(float inch) {
    return inch * 2.54F;
}