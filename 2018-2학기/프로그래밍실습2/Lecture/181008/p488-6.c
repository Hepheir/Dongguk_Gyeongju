#include <stdio.h>

#define PI 3.141592

float area(float);
float circumference(float);

int main(void) {
    float r;

    scanf("%f", &r);

    printf("Area : %.2f\n", area(r));
    printf("Circumference : %.2f\n", circumference(r));

    return 0;
}

float area(float radius) {
    return radius * radius * PI;
}

float circumference(float radius) {
    return 2 * radius * PI;
}