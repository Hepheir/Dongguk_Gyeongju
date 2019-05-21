#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void korstr2num(const char* str);
void numstr2kor(const char* str);

unsigned char *kornum_set[] = { "��", "��", "��", "��", "��", "��", "��", "ĥ", "��", "��" };

void hw05_7() {
	char st[20];
	unsigned char uc;

	printf("���� �Է��� Enter>");
	scanf("%s", st);

	uc = st[0];
	if (uc > 122) { // �ѱ� ���� �迭(2byte) �� ù ��° ������ ASCII �ڵ尡 123 �̻��̸� �ѱ۷� ����.
		printf("�ѱ��Դϴ�.\n");
		korstr2num(st);
	}
	else {
		printf("�����Դϴ�.\n");
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
		str += 2; // 2 byte�� �ǳ� �ٱ�
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