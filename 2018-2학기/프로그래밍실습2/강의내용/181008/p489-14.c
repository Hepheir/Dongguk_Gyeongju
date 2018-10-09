#include <stdio.h>

void copyArray(int from[], int to[], int n);
void printIntArray(int array[], int length);

int main(void) {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    int b[10] = { 0 };

    // Before
    printf("Array 'a' : ");
    printIntArray(a, 10);
    
    printf("Array 'b' : ");
    printIntArray(b, 10);

    // Copy
    printf("Copy 'b' with 'a'\n");
    copyArray(a, b, 10);
    
    // After
    printf("Array 'b' : ");
    printIntArray(b, 10);

    return 0;
}

void copyArray(int from[], int to[], int n) {
    for (int i = 0; i < n; i++)
        to[i] = from[i];
}

void printIntArray(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);

    puts("");
}