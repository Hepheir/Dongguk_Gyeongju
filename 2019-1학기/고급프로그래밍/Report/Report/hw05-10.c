#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* reverse_han(char* korstr);
char* remove_blank(const char* str);

char buffer[128];

void hw05_10() {
	char* st1 = "프로그램";
	char* st2 = "파일 변환";

	printf("%s\n", reverse_han(st1));
	printf("%s\n", st1);

	printf("%s\n", remove_blank(st2));
	printf("%s\n", st2);
}

char* reverse_han(char* kst) {
	int len = strlen(kst);

	for (int i = 0; i < len; i += 2) {
		strncpy(buffer+i, kst+(len-2 - i), 2);
	}
	buffer[len] = '\0';

	return buffer;
}
char* remove_blank(const char* st) {
	int pivot = 0;
	while (*st) {
		while (*st == ' ')
			st++;
		strncpy(buffer + pivot, st, 2);
		st += 2;
		pivot += 2;
	}
	buffer[pivot] = '\0';
	return buffer;
}