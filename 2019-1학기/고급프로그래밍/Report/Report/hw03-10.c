#include <stdlib.h>
#include <time.h>
#include <math.h>

void hw03_10() {
	srand(time(NULL));

	int m;
	int k = rand() % 40 + 11; // 11~50

	printf("���ڸ� �Է� (0:����) : ");

	while (1) {
		printf(">>> ");
		scanf("%d", &m);

		if (m == 0) {
			printf("�����մϴ�.\n");
			break;
		}

		if (m == k) {
			printf("�¾���.\n");
			break;
		}

		printf("[%d] -> ", m);
		if (abs(k - m) < 10) {
			printf("���� ");
		} else {
			printf("���� ");
		}

		if (k < m) {
			printf("�۰�");
		}
		else {
			printf("ũ��");
		}
		printf("\n");
	}
}