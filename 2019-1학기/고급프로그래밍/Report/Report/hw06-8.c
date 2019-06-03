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
		{"골프", 20000},
		{"수영", 17000},
		{"헬스", 12000},
		{"탁구", 10000},
		{"샤워", 5000}
	};

	char buffer[120] = "탁구4 샤워2 골프3";

	char order_words[7];
	int n_of_orders = 0;
	struct order orders[40];

	printf("주문내용을 입력하고 Enter>");
	//gets(buffer);
	printf("%s\n", buffer);

	// 주문 단위로 버퍼 처리
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
	
	print_recipt("영수증", orders, n_of_orders);
	print_recipt("매출전표", orders, n_of_orders);
}

void print_recipt(char* title, struct order orders[], int size) {
	printf("\n%s\n", title);
	printf("종목    수량    단가       금액\n");
	printf("----------------------------------\n");
	struct order ord;
	for (int i = 0; i < size; i++) {
		ord = orders[i];
		printf("%s %6d %8d원 %8d원\n", ord.course.name, ord.quant, ord.course.charge, (ord.course.charge * ord.quant));
	}
	printf("\n");
}