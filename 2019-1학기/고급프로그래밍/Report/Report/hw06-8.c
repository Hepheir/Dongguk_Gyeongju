#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct course {
	char *name;
	int charge;
};

struct order {
	struct course course;
	int quant;
};

void print_recipt(char* title, struct order orders[], int size);

void hw06_8() {
	struct course course_list[5] = {
		{"����", 20000},
		{"����", 17000},
		{"�ｺ", 12000},
		{"Ź��", 10000},
		{"����", 5000}
	};

	char buffer[120] = "Ź��4 ����2 ����3";

	char order_words[7];
	int n_of_orders = 0;
	struct order orders[40];

	printf("�ֹ������� �Է��ϰ� Enter>");
	//gets(buffer);
	printf("%s\n", buffer);

	// �ֹ� ������ ���� ó��
	for (int i = 0; i < strlen(buffer); i += 6) {
		strncpy(order_words, &buffer[i], 6);
		order_words[6] = '\0';

		for (int course_num = 0; course_num < 5; course_num++)
			if (strncmp(order_words, course_list[course_num].name, 4) == 0) {
				orders[n_of_orders].course = course_list[course_num];
				orders[n_of_orders].quant = atoi(&order_words[4]);
				n_of_orders++;
				break;
			}
	}
	
	print_recipt("������", orders, n_of_orders);
	print_recipt("������ǥ", orders, n_of_orders);
}

void print_recipt(char* title, struct order orders[], int size) {
	printf("\n%s\n", title);
	printf("����    ����    �ܰ�       �ݾ�\n");
	printf("----------------------------------\n");
	struct order ord;
	for (int i = 0; i < size; i++) {
		ord = orders[i];
		printf("%s %6d %8d�� %8d��\n", ord.course.name, ord.quant, ord.course.charge, (ord.course.charge * ord.quant));
	}
	printf("\n");
}