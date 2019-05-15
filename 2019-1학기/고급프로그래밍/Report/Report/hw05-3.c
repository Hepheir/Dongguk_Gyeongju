//#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

void hw05_3() {
	int num1 = 14;
	long num2 = 512;
	char s[25];
	//itoa(num1, s, 2);
	// _itoa(num1, s, 2);
	 _itoa_s(num1, s, sizeof(s), 2);

	printf("정수:%d, 2진구문자열:%s\n", num1, s);

	//ltoa(num2, s, 16);
	//_ltoa(num2, s, 16);
	_ltoa_s(num2, s, sizeof(s), 16);

	printf("정수:%ld, 16진수문자열:%s\n", num2, s);
}