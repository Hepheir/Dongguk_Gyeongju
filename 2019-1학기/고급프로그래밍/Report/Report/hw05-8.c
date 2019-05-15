#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SUPERS 3
char* kor_unit_super[SUPERS] = { "", "¸¸", "¾ï" };
unsigned long unit_super[SUPERS] = { 1, 10000, 100000000 };

#define SUBS 4
char* kor_unit_sub[SUBS] = { "", "½Ê", "¹é", "Ãµ" };
unsigned long unit_sub[SUBS] = { 1, 10, 100, 1000 };

char* kor_unit_digit[] = { "", "ÀÏ", "ÀÌ", "»ï", "»ç", "¿À", "À°", "Ä¥", "ÆÈ", "±¸" };

void hw05_8() {
	unsigned long value;

	printf("¼ýÀÚ¸¦ ÀÔ·Â > ");
	scanf("%lu", &value);

	int block, digit;
	for (int super = SUPERS; super >= 0; super--) {
		block = value / unit_super[super];
		if (block) {
			for (int sub = SUBS; sub >= 0; sub--) {
				digit = (block % (unit_sub[sub] * 10)) / unit_sub[sub];
				if (digit)
					printf("%s%s", kor_unit_digit[digit], kor_unit_sub[sub]);
			}
			printf("%s ", kor_unit_super[super]);
		}
		value -= block * unit_super[super];
	}
	printf("\n");
}