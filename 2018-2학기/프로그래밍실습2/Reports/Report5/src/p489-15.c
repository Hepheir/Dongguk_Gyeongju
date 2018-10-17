#include <stdio.h>

int isequalarray(int a[], int b[], int n);

int main(void) {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    int b[10] = { 0 };
    int c[8] = { 2, 4, 8, 16, 32, 64, 128, 256 };
    int d[8] = { 2, 4, 8, 16, 32, 64, 128, 256 };

    printf("is 'a' equals 'b' : ");
    if (isequalarray(a, b, sizeof(a)))
        puts("true");
    else
        puts("false");

    printf("is 'c' equals 'd' : ");
    if (isequalarray(c, d, sizeof(c)))
        puts("true");
    else
        puts("false");

    return 0;
}

int isequalarray(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return 0;
    }

    return 1;
}