#include <stdio.h>

int main(void) {
	int input;

	do {
		puts("\t [1] 한식");
		puts("\t [2] 양식");
		puts("\t [3] 분식");
		puts("\t [4] 기타");
		printf("메뉴 번호 선택 후 [Enter] : ");
		scanf("%d", &input);
		printf("선택 메뉴 %d\n", input);

		if (input <= 4 && input >= 1)
			break;
	} while (1);

	return 0;
}