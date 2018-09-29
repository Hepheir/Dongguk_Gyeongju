#include <stdio.h>

int main() {
    int arr1[4];
    int arr2[] = { 1, 2, 3, 4 };
    int arr3[4] = { 1, 2, 3, 4 };
    int arr4[4] = { 0 };

    int i;

    for (i = 0; i < 4; i ++)
        printf("%d ", arr1[i]);
    puts("");

    for (i = 0; i < 4; i ++)
        printf("%d ", arr2[i]);
    puts("");

    for (i = 0; i < 4; i ++)
        printf("%d ", arr3[i]);
    puts("");

    for (i = 0; i < 4; i ++)
        printf("%d ", arr4[i]);
    puts("");

    return 0;
}