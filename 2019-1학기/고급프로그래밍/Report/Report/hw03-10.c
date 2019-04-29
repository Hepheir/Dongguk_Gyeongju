#include <stdlib.h>
#include <time.h>
#include <math.h>

void hw03_10() {
	srand(time(NULL));

	int m;
	int k = rand() % 40 + 11; // 11~50

	printf("숫자를 입력 (0:종료) : ");

	while (1) {
		printf(">>> ");
		scanf("%d", &m);

		if (m == 0) {
			printf("종료합니다.\n");
			break;
		}

		if (m == k) {
			printf("맞았음.\n");
			break;
		}

		printf("[%d] -> ", m);
		if (abs(k - m) < 10) {
			printf("조금 ");
		} else {
			printf("많이 ");
		}

		if (k < m) {
			printf("작게");
		}
		else {
			printf("크게");
		}
		printf("\n");
	}
}