#include <stdio.h>

float CtoF(float);

int main(void) {
    float cel;

    for (cel = 0; cel <= 100; cel += .5F)
        printf("%.2fC = %.2fF\n", cel, CtoF(cel));
}

float CtoF(float _cel) {
    return _cel * (9.0F / 5.0F) + 32;
}