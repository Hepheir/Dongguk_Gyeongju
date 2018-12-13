#include <stdio.h>

void copyarray(int* source, int* dest, int size);

int main(void)
{
    int ary[7] = { 10, 20, 30, 40, 50, 60, 70 };
    int dest[7];
    int size = sizeof(ary) / sizeof(int);

    copyarray(ary, dest, size);

    int i;
    printf("ary: ");
    for (i = 0; i < size; i++)
        printf("[%2d] ", ary[i]);
    printf("\n");

    printf("dest: ");
    for (i = 0; i < size; i++)
        printf("[%2d] ", dest[i]);
    printf("\n");

    return 0;
}

void copyarray(int* source, int* dest, int size)
{
    for (int i = 0; i < size; i++)
        *(dest + i) = *(source + i);
}