#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "C and C++\t language are best!";
    char *delimiter = " ,\t!";

    printf("str1 = %u\n", str1); // !
    printf("delimiter = %u\n", delimiter); // !

    printf("문자열 \"%s\"을 >>\n", str1);
    printf("구분자[%s]를 이용하여 토큰을 추출 >>\n", delimiter);
    char *ptoken = strtok(str1, delimiter);
    
    printf("ptoken = %u\n", ptoken); // !

    while (ptoken != NULL)
    {
        printf("%s\n", ptoken);
        ptoken = strtok(NULL, delimiter);
    }
    return 0;
}