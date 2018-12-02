#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "C and C++\t language are best!";
    char *delimiter = " ,\t!";
    // char *next_token; //함수 strtok_s()의 사용

    printf("문자열 \"%s\"을 >>\n", str1);
    printf("구분자[%s]를 이용하여 토큰을 추출 >> \n", delimiter);
    char *ptoken = strtok(str1, delimiter);
    // char *ptoken = strtok_s(str1, delimiter, &next_token); //함수 strtok_s()의 사용
    while ( ptoken != NULL )
    {
        printf("%s\n", ptoken);
        ptoken = strtok(NULL, delimiter);
        // ptoken = strtok_s(NULL, delimiter, &next_token); // 다음 토큰을 반환
    }

    return 0;
}