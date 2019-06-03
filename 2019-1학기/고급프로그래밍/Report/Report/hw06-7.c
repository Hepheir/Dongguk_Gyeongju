#include <stdio.h>

typedef struct _chart {
	char name[40];
	int price;
	int quantity;
} Chart;

void hw06_7() {
	Chart chart[5] = {
		{"hard disk", 135000, 5},
		{"CPU", 235000, 7},
		{"main board", 162000, 9},
		{"monitor", 260000, 4},
		{"DVD-RW", 73500, 6}
	};

	int total = 0;
	Chart *stuff;
	printf("    %s    %s  %s    %s\n", "품명", "단가(원)", "수량", "금액");
	printf("=====================================\n");
	for (int i = 0; i < 5; i++) {
		stuff = chart + i;
		printf("%10s %8d %4d %10d\n", stuff->name, stuff->price, stuff->quantity, (stuff->price) * (stuff->quantity));
		total += (stuff->price) * (stuff->quantity);
	}
	printf("=====================================\n");
	printf("Total price : %d\n", total);
}