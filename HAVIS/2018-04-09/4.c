#include <stdio.h>

int main(void)
{
    int a = 10, b = 11, c = 0;
    // a = 10, b = 11, c = 0
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (++a == 11) && (++b == 12);
    // a = 11, b = 12, c = 1 AND DO
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (a-- == 10) && (b-- == 12);
    // a = 10, b = 12, c = 0 AND PASS
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (a++ == 10) || (b++ == 11);
    // a = 11, b = 12, c = 1 OR PASS
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (--a == 11) || (--b == 11);
    // a = 10, b = 11, c = 1 OR DO
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}