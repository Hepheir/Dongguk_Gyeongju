#include <stdio.h>

int main() {
	// 문자형 배열을 선언하면서 초기값으로 첫 원소에 문자 'A'를 대입한 후
	// 다른 알파벳 대문자를 배열에 알파벳순으로 저장한 후 출력하는 플그램
	// 구현

	char ch[26];

	for (int i = 0; i < 26; i++)
		ch[i] = 'A' + i;

	for (int i = 0; i < 26; i++)
		printf("%c", ch[i]);

	system("pause");
	return 0;
}