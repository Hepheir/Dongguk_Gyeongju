#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "user.h"

void hw06_1() {
	struct user d;
	strcpy(d.name, "±Ë∏Ì»Ø");
	strcpy(d.phone, "011-123-4567");
	d.quick = 1;
	printf("name  : %s\n", d.name);
	printf("phone : %s\n", d.phone);
	printf("quick : %d\n", d.quick);
}