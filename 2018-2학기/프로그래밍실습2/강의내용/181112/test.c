#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[50] = "Hello, world!";
    printf("%s\n", (char *) memset(src, '!', 14));
    return 0;
}