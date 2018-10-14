#include <stdio.h>

int isEqualArray(int a[], int b[], int n);
void printIntArray(int array[], int length);

int main(void) {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    int b[10] = { 0 };
    int c[8] = { 2, 4, 8, 16, 32, 64, 128, 256 };
    int d[8] = { 2, 4, 8, 16, 32, 64, 128, 256 };

    printf("Array 'a' : ");
    printIntArray(a, 10);
    
    printf("Array 'b' : ");
    printIntArray(b, 10);

    printf("Array 'c' : ");
    printIntArray(c, 8);
    
    printf("Array 'd' : ");
    printIntArray(d, 8);

    

    printf("is 'a' equals 'b' : ");
    if (isEqualArray(a, b, 10))
        puts("true");
    else
        puts("false");

    printf("is 'c' equals 'd' : ");
    if (isEqualArray(c, d, 8))
        puts("true");
    else
        puts("false");

    return 0;
}

int isEqualArray(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return 0;
    }

    return 1;
}

void printIntArray(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);

    puts("");
}