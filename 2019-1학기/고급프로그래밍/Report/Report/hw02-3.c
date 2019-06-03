#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hw02_3() {
	int number;
	int digit;

	printf("¼¼ ÀÚ¸® Á¤¼ö ÀÔ·Â : ");
	scanf("%d", &number);

	printf(">>> ");
	for (int i = 100; i > 0; i /= 10) {
		digit = number / i;
		number %= i;
		switch (digit) {
		case 0:
			printf("¿µ");
			break;
		case 1:
			printf("ÀÏ");
			break;
		case 2:
			printf("ÀÌ");
			break;
		case 3:
			printf("»ï");
			break;
		case 4:
			printf("»ç");
			break;
		case 5:
			printf("¿À");
			break;
		case 6:
			printf("À°");
			break;
		case 7:
			printf("Ä¥");
			break;
		case 8:
			printf("ÆÈ");
			break;
		case 9:
			printf("±¸");
			break;
		}
	}
	printf("\n");
}