char *kor_nums[] = { "��", "��", "��", "��", "��", "��", "��", "ĥ", "��", "��" };

void hw05_7() {
	char st[3];
	unsigned char uc;
	printf("���� �Է��� Enter>");
	scanf("%s", st);
	uc = st[0];
	if (uc ) {
		printf("�ѱ��Դϴ�.\n");
		kor2num()
	}
	else {
		printf("�����Դϴ�.\n");
	}
}

void num2kor(unsigned long ul) {
	int scale;
	int digit;

	for (scale = 1; ul / scale; scale *= 10);

	while (scale > 0) {
		printf("%s", kor_nums[(ul % (10 * scale)) / scale]);
		scale /= 10;
	}
}

void kor2num(const char* str) {
	unsigned long retval;

	int length = 0;
	while (*(str + length++));

	int scale;
	int digit;
	while (length > 0) {
		scale = 1;
		for (int i = 0; i < length; i++) scale *= 10;

		for (digit = 0; digit < 10; digit++)
			if (str[length - 1] == kor_nums[digit])
				break;
		retval += digit * scale;
	}
	printf("%ld", retval);
}