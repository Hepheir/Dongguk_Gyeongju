#include <stdio.h>
void hw02_5() {
	int age;
	char name[20];

	printf("���̿� �̸� �Է� : ");
	scanf_s("%d %s", &age, name, 20);

	printf(">>> %d�� %s�Դϴ�.\n", age, name);
}