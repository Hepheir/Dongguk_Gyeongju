#pragma warning ( disable : 4996 )
#include <stdio.h>

void Q_444_8() {
	int i, j;

	int histogram[10] = { 0 };


	///////// input /////////
	int input;

	for (i = 0; i < 20; i++)
	{
		scanf("%d", &input);
		histogram[input]++;
	}

	///////// output /////////
	for (i = 0; i < 10; i++)
	{
		printf("%2d번은 %2d번 > ", i, histogram[i]);

		for (j = 0; j < histogram[i]; j++)
			printf("=");

		puts("");
	}
}
