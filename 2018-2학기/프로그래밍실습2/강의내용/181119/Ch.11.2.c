#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char strl[] = "C and C++\t language are best!";
    char* delimiter = " ,\t!";

    printf("문자열 \"%s\"을 >>\n", strl);
    printf("구분자[%s]를 이용하여 토큰을 추출 >>\n", delimiter);

    char* ptoken = strtok(strl, delimiter);

    while (ptoken != NULL)
    {
        printf("%s\n", ptoken);
        ptoken = strtok(NULL, delimiter);
    }

    return 0;
}