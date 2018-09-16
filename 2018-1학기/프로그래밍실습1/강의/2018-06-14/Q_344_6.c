#pragma warning (disable : 4996)
#include <stdio.h>

void Q_344_6() {
	int i, j;

	for (i = 0; i < 8; i++) {
		// j : 7 ~ i+1
		for (j = 7; j > i; j--)
			printf(" ");

		// j : i ~ 1
		for (	  ; j > 0; j--)
			printf("%d", j);

		// j : 0 ~ i
		for (	  ; j <= i; j++)
			printf("%d", j);

		puts("");
	}
}