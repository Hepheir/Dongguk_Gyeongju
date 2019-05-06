#include <stdlib.h>
#include <time.h>
#define LOTTO_NUMS 6

void createRandNum(int numset[LOTTO_NUMS], int index);

void hw04_2() {
	srand(time(NULL));
	int selected_num[LOTTO_NUMS];
	int n = 5;

	printf("�ζǹ�ȣ ����\n");
	printf("����� �ζǹ�ȣ set�� ���� �Է��ϰ� Enter>");
	scanf("%d", &n);


	for (int set = 0; set < n; set++) {
		// Generates random number set.
		for (int i = 0; i < LOTTO_NUMS; i++)
			createRandNum(selected_num, i);

		// Prints the set
		printf("set %d:", set+1);
		for (int i = 0; i < LOTTO_NUMS; i++)
			printf(" %2d", selected_num[i]);
		printf("\n");
	}
}

void createRandNum(int numset[LOTTO_NUMS], int index) {
	numset[index] = rand() % 45 + 1;
	for (int pivot = 0; pivot < index; pivot++)
		if (numset[pivot] == numset[index]) {
			createRandNum(numset, index); // �ߺ� ����
			break;
		}
}