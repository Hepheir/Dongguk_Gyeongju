#include <stdio.h>
#include "user.h"

void hw06_2() {
	User d[2] = {
	{"���ȯ", "011-123-4567", 1},
	{"������", "010-120-5638", 5} };
	User *pt;
	int i;
	pt = d;
	for (i = 0; i < 2; i++) {
		printf("name :%s\n", (pt + i)->name);
		printf("phone:%s\n", (pt + i)->phone);
		printf("quick:%d\n", (pt + i)->quick);
		printf("\n");
	}
}