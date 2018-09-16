#include <stdio.h>

int main(){
    int a = 4, b = 6;
    double x = 3.3, y = 4.7;

    printf("%d ", a + b > y && x < y);
    printf("%d ", a++ - --b * 2);
    printf("%f ", a > b ? x + 1 : y * 2);
    printf("%f ", x += 3 && y + 2);
    printf("%f\n", (x = x + 1, y = y + 1));

    return 0;
}