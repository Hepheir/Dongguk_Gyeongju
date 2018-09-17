#include <stdio.h>

int main() {
	int data[] = { 1, 11, 111, 2, 22, 222, 3, 33, 333 };

	for (int i = 0; i < 9; i++)
		data[i] += 100;

	return 0;
}