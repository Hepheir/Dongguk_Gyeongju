#include <stdio.h>
#include <string.h>

int mystrlen(const char* p) {
    int length;
    for (length = 0; *(p + length); length++);
    return length;
}

int main(void)
{
    char str[80];

    gets(str);

    printf("str = %s\n", str);
    printf("strlen(str) = %d\n", strlen(str));
    printf("mystrlen(str) = %d\n", mystrlen(str));

    return 0;
}