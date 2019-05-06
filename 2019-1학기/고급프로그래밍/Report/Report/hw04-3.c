#include <stdlib.h>
#include <time.h>

void hw04_3() {
	srand(time(NULL));

	int randomNumberSet[100];
	int hist[10] = { 0 };

	int randnum;

	printf("积己等 荐:\n");
	for (int i = 0; i < 100; i++) {
		randnum = rand() % 9 + 1;
		hist[randnum]++;
		randomNumberSet[i] = randnum;
		printf(" [%d]", randnum);
	}
	printf("\n\n");

	for (int i = 1; i <= 9; i++)
		printf("[%d] 后档荐 : %2d, 犬伏 : %.2f\n", i, hist[i], hist[i] / 100.F);
}