// p.454 예제 10-1 변형

#include <stdio.h>

int main(void) {
    int a = 3, b = 5;

    int add2(int a, int b);
    int sub2(int a, int b);

    int sum = add2(a, b);
    printf("main > a : %d\n", a);

    int sub = sub2(a, b);

    printf("합: %d\n", sum);
    printf("차: %d\n", sub);

    return 0;
}

int add2(int a, int b) {
    int sum = a + b;

    a = a + 5;
    printf("add2 > a : %d\n", a);

    return (sum);
}

int sub2(int a, int b) {
    int sub = a - b;

    return (sub);
}