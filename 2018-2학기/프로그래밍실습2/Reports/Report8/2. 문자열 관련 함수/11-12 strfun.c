#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "JAVA 2017 go C#";
    printf("%d\n", strlen("java"));
    printf("%s, ", _strlwr(str));
    printf("%s, ", _strupr(str));

    printf("%s, ", strstr(str, "VA"));
    printf("%s\n", strchr(str, 'A'));
}

char* strchr(char* str, char ch) {
    for (int i = 0; str[i]; i++)
        if (str[i] == ch) return (str + i);
    return NULL;
}