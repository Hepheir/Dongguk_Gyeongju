#include <stdio.h>

int main(void) {
	int count = 1;

	while (count <= 3) {
		printf("C언어 재밌네요!\n");
		count++;
	}
	printf("\n제어변수 count => %d\n", count);

	return 0;
}