#include <stdio.h>

int main() {
    char src[50] = "https://github.com/Hepheir";

    printf("문자배열 src = %s\n", src);

    for (int i = 0; i != '\0'; i++)
        printf("%c", src[i]);
    
    printf("\n");
    return 0;
}