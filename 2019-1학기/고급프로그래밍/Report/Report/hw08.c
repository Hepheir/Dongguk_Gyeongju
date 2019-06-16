#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char* string;

void hw08_1() {
	//
}

void hw08_2() {
	//
}

void hw08_3() {
	//
}

void hw08_4() {
	//
}

void hw08_5() {
	//
}

void hw08_6() {
	//
}

void hw08_7() {
	string fname_in = "hw08/price.txt";
	string fname_out = "hw08/sales.txt";
	FILE *fp;
	typedef struct {
		char title[20];
		int price;
		int count;
	} reciept;

	if ((fp = fopen(fname_in, "r")) == NULL) {
		printf("File open error\n");
		exit(1);
	}

	reciept list[4];

	int size = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s %d", list[size].title, &list[size].price);
		printf("%s의 수량 : ", list[size].title);
		scanf("%d", &list[size].count);
		size++;
	}
	fclose(fp);

	if ((fp = fopen(fname_out, "w")) == NULL) {
		printf("File open error\n");
		exit(1);
	}

	printf("%6s %8s %4s %10s\n", "종목", "단가", "수량", "금액");
	printf("====== ======== ==== ==========\n");

	for (int i = 0; i < size; i++) {
		reciept elem = list[i];

		fprintf(fp, "%s %d %d\n", elem.title, elem.price, elem.count);
		printf("%6s %8d %4d %10d\n", elem.title, elem.price, elem.count, (elem.price)*(elem.count));
	}
	fclose(fp);
}

void hw08_8() {
	string fname = "hw08/lotto.txt";
	FILE *fp;
	int numset[6];
	int n_sets;

	srand(time(NULL));
	if ((fp = fopen(fname, "w")) == NULL) {
		printf("fopen error\n");
		exit(1);
	}

	printf("Number of the n set : ");
	scanf("%d", &n_sets);
	int set, i, chk;
	for (set = 0; set < n_sets; set++) {
		for (i = 0; i < 6; i++) {
			numset[i] = rand() % 45 + 1;
			for (chk = 0; chk < i; chk++)
				if (numset[chk] == numset[i]) {
					i--;
					break;
				}
			if (chk == i)
				fprintf(fp, "%d ", numset[i]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}

void _printPercent(int total) {
	static int count = 0;
	printf("\r%12.8f%%", (float)(++count) / total * 100);
}

void hw08_9() {
	string fname = "hw08/number.txt";
	FILE *fp;
	int repeats = 700000;

	// 생성부분
	srand(time(NULL));
	if ((fp = fopen(fname, "w")) == NULL) {
		printf("fopen error\n");
		exit(1);
	}
	for (int i = 0; i < repeats; i++) {
		fprintf(fp, "%d\n", rand() % 10);
		_printPercent(2 * repeats);
	}
	fclose(fp);

	// 빈도 측정 부분
	int hist[10] = { 0 };
	int num;

	if ((fp = fopen(fname, "r")) == NULL) {
		printf("fopen error\n");
		exit(1);
	}

	for (int i = 0; i < repeats; i++) {
		fscanf(fp, "%d", &num);
		hist[num]++;
		_printPercent(2 * repeats);
	}
	fclose(fp);

	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%2d : %4d번\n", i, hist[i]);
	}
}


void hw08_10() {
	string fname = "hw08/alpha.txt";
	FILE *fp;
	int repeats = 10000;
	int done = 0;

	// 생성부분
	srand(time(NULL));
	if ((fp = fopen(fname, "w")) == NULL) {
		printf("fopen error\n");
		exit(1);
	}
	for (int i = 0; i < repeats; i++) {
		fprintf(fp, "%c\n", rand() % 23 + 'A');
		_printPercent(2 * repeats);
	}
	fclose(fp);

	// 빈도 측정 부분
	int hist[23] = { 0 };
	char alpha;

	if ((fp = fopen(fname, "r")) == NULL) {
		printf("fopen error\n");
		exit(1);
	}

	for (int i = 0; i < repeats; i++) {
		fscanf(fp, "%c", &alpha);
		hist[alpha - 'A']++;
		_printPercent(2 * repeats);
	}
	fclose(fp);

	printf("\n");
	for (int i = 0; i < 23; i++) {
		printf("%2c : %4d번\n", i+'A', hist[i]);
	}
}