#include <stdio.h>

void swapStr(char *a, char *b, int length);

int main(void) {
    char a[] = "Dongguk!!!";
    char b[] = "University!!";
    
    puts("Before");
    printf("%s\n", a);
    printf("%s\n", b);

    swapStr(a, b, 13);

    puts("After");
    printf("%s\n", a);
    printf("%s\n", b);
}


void swapStr(char *a, char *b, int length) {
    char mem;
    for (int i = 0; i < length; i++)
    {
        mem = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = mem;
    }
}