#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void hw05_5() {
	char s[15] = "program";
	char *strl = "compile";
	printf("original s : %s\n", s);
	printf("length of s: %d\n", strlen(s));
	strncpy(s, strl, 4);
	printf("\ns after strncpy : %s\n", s);
	printf("length of s: %d\n", strlen(s));
	s[4] = '\0';
	printf("\ns after NULL : %s\n", s);
	printf("length of s: %d\n", strlen(s));
}