#include <stdio.h>

void copyarray(int from[], int to[], int n);

int main(void) {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    int b[10] = { 0 };

    copyarray(a, b, sizeof(a));
    
    printf("Copied Array 'b' : ");

    for (int i = 0; i < 10; i++)
        printf("%d ", b[i]);

    puts("");

    return 0;
}

void copyarray(int from[], int to[], int n) {
    for (int i = 0; i < n; i++)
        to[i] = from[i];
}