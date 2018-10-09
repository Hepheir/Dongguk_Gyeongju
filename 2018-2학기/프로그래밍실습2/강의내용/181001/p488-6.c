#include <stdio.h>

#define PI 3.14

double area(double radius);
double circumference(double radius);

int main(void) {
    double r;

    printf("실수 r을 입력 (반지름) : ");
    scanf("%lf", &r);

    printf("면적 : %.2lf\n", area(r));
    printf("둘레 : %.2lf\n", circumference(r));

    return 0;
}

double area(double radius) {
    return PI * radius * radius;
}

double circumference(double radius) {
    return 2 * PI * radius;
}