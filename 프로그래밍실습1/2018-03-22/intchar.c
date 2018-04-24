// intchar.c: 아스키 코드값 126 문자 '~'의 다양한 출력

#include <stdio.h>

int main(void)
{
	int ch = 126;

	printf("%d\n", 126);
	printf("%c\n", ch);
	printf("%c\n", '\176');
	printf("%c\n", '\x7E');

	return 0;
}