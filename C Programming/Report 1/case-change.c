/*
	문자변수를 활용한 임의의 프로그램.
    >>  알파벳 대문자를 소문자로, 혹은 소문자를 대문자로 바꿔주는 프로그램.
	
	학번 2018212236
	이름 김동주
	Ver 1.0 / 2018-03-19 / case-change.c
*/

#include <stdio.h>

int main(void)
{
    // 대소문자를 바꿀 문자 변수 할당.
    char c = 'a';
    printf("Before case change\nc: %c\n", c);


    // ASCII는 65부터 'A', 97부터 'a'이다. -> 같은 알파벳의 대소문자 코드 값의 차는 32이다.
    
    if (c < 97)
    {
        c = c + 32; // `c`가 대문자일 경우 `c`를 소문자로 변경.
    }
    else
    {
        c = c - 32; // 반대의 경우는 소문자를 대문자로 변경.
    }

    // 결과 출력
    printf("After case change\nc: %c\n", c);
    return 0;
}