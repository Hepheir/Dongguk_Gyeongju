#include <stdio.h>

int main(void) {
	int input;

	do {
		puts("\t [1] �ѽ�");
		puts("\t [2] ���");
		puts("\t [3] �н�");
		puts("\t [4] ��Ÿ");
		printf("�޴� ��ȣ ���� �� [Enter] : ");
		scanf("%d", &input);
		printf("���� �޴� %d\n", input);

		if (input <= 4 && input >= 1)
			break;
	} while (1);

	return 0;
}