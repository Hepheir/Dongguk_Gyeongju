#include <stdio.h>

struct human {
	char name01[10];
	char *name92;
} data01 = { "Miss Kim", "Mr Park" };
struct company {
	char com_name[10];
	struct human people;
	int salary;
} data02 = {"Choi", "Kim", "Park", 500};

int hw06_6(void) {
	printf("%s\n", data02.com_name);
	printf("%s\n", data02.people.name01);
	printf("%c\n", data01.name01[1]);
	printf("%d\n", data02.salary);
	return 0;
}