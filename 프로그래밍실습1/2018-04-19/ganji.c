#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int year, gan, ji;

	printf("�⵵�� �Է�: ");
	scanf("%d", &year);

	gan = (year + 6) % 10; // 2017 % 10 == 7 , ���� (�� == 3) , 7 >>> 3, 7 - 4 == 3,  7 + 6 == 13 >> 13 % 10 == 3
	ji = (year + 8) % 12;

	// 10�� ���
	switch (gan) {
	case 0:
		printf("��");
		break;
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	case 4:
		printf("��");
		break;
	case 5:
		printf("��");
		break;
	case 6:
		printf("��");
		break;
	case 7:
		printf("��");
		break;
	case 8:
		printf("��");
		break;
	case 9:
		printf("��");
		break;
	}
		
	// 12�� ���
	switch (ji) {
	case 0:
		printf("��");
		break;
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	case 4:
		printf("��");
		break;
	case 5:
		printf("��");
		break;
	case 6:
		printf("��");
		break;
	case 7:
		printf("��");
		break;
	case 8:
		printf("��");
		break;
	case 9:
		printf("��");
		break;
	case 10:
		printf("��");
		break;
	case 11:
		printf("��");
		break;
	}

	// ������ ���
	printf("��\n");

	return 0;
}
