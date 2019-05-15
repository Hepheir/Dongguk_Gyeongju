#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void korstr2num(const char* str);
void numstr2kor(const char* str);

unsigned char *kornum_set[] = { "영", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구" };

void hw05_7() {
	char st[20];
	unsigned char uc;

	printf("문자 입력후 Enter>");
	scanf("%s", st);

	uc = st[0];
	if (uc > 122) { // 한글 문자 배열(2byte) 중 첫 번째 문자의 ASCII 코드가 123 이상이면 한글로 구분.
		printf("한글입니다.\n");
		korstr2num(st);
	}
	else {
		printf("숫자입니다.\n");
		numstr2kor(st);
	}
	printf("\n");
}

void korstr2num(char* str) {
	while (*str) {
		for (int digit = 0; digit <= 9; digit++) {
			if (strncmp(str, kornum_set[digit], 2) == 0) {
				printf("%d", digit);
				break;
			}
		}
		str += 2; // 2 byte씩 건너 뛰기
	}
}

void numstr2kor(const char* str) {
	int length = strlen(str);
	int digit;
	for (int i = 0; i < length; i++) {
		digit = str[i] - '0'; // 0x30
		printf("%s", kornum_set[digit]);
	}
}