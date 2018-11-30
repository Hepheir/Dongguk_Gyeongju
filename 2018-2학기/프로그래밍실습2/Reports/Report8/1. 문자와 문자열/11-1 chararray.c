#include <stdio.h>

int main(void)
{
    char ch = 'A';
    printf("%c %d\n", ch, ch);

    char java[] = { 'J', 'A', 'V', 'A', '\0' };
    printf("%s\n", java);

    char c[] = "C language";
    printf("%s\n", c);

    char csharp[5] = "C#";
    printf("%s\n", csharp); // 문자열 출력을 위해 배열 이름과 형식 제어문자 %s를 이용한다.

    printf("%c%c\n", csharp[0], csharp[1]);

    return 0;
}