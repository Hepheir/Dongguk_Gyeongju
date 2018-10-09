#include <stdio.h>

int square(int);
int cube(int);

int main(void) {
    int N;

    scanf("%d", &N);

    printf("%d ^ 5 = %d\n", N, square(N) * cube(N));
    return 0;
}

int square(int n) {
    return n * n;
}

int cube(int n) {
    return square(n) * n;
}