#include <stdio.h>

int main(void)
{
    char* java = "java";
    printf("%s ", java);

    int i = 0;
    while (java[i])
        printf("%c", java[i++]);
    printf(" ");
    
    // java[i]는 *(java + i)와 동일한 표현 방식이므로 java[i++]도 *(java + i++)와 같다.
    
    i = 0;
    while (*(java + i) != '\0')
        printf("%c", *(java + i++));
    printf("\n");

    java[0] = 'J';

    return 0;
}