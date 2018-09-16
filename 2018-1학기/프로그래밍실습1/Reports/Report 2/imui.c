#include <stdio.h>

int main(void)
{
    // 5자리 문자를 암호화 하는 프로그램
    // 'A' ~ 'Z' : 65 ~ 90
    
    char c = 'H',
        c2 = 'E',
        c3 = 'L',
        c4 = 'L',
        c5 = 'O';

    printf("입력한 문자열: %c%c%c%c%c\n", c, c2, c3, c4, c5);

    // char형의 산술 연산을 사용하여 암호화 Encrypt
    int ce1 = ( c + 9) * 2,
        ce2 = (c2 + 9) * 3,
        ce3 = (c3 + 9) * 4,
        ce4 = (c4 + 9) * 5,
        ce5 = (c5 + 9) * 6;

    printf("암호화한 문자열: %c%c%c%c%c\n", ce1, ce2, ce3, ce4, ce5);

    // 위의 암호화 과정을 역순으로 역연산 하여 복호화.
    char cd = ce1 / 2 - 9,
        cd2 = ce2 / 3 - 9,
        cd3 = ce3 / 4 - 9,
        cd4 = ce4 / 5 - 9,
        cd5 = ce5 / 6 - 9;
    
    printf("해독한 문자열: %c%c%c%c%c\n", cd, cd2, cd3, cd4, cd5);

    return 0;
}