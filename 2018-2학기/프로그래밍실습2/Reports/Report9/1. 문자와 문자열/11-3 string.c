#include <stdio.h>

int main(void)
{
    char c[] = "C C++ Java";

    printf("&c = %u\n", &c); // !

    printf("%s\n", c);
    c[5] = '\0';
    printf("%s\n%s\n", c, (c + 6));

    c[5] = ' ';
    char *p = c;

    printf("*p = %c\n", *p); // !
    printf(" p = %u\n", p); // !

    while (*p)
        printf("%c", *p++);
    printf("\n");

    printf("*p = %c\n", *p); // !
    printf(" p = %u\n", p); // !

    return 0;
}