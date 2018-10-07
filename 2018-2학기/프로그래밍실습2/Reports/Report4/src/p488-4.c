#include <stdio.h>

int int3_getMax(int, int, int);

int main(void) {
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);

    printf("Max : %d\n", int3_getMax(a, b, c));
    return 0;
}

int int3_getMax(int a, int b, int c) {
    int max = a;

    if (b > max)
        max = b;

    if (c > max)
        max = c;
    
    return max;
}