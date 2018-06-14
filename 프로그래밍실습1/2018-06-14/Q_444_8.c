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
		printf("%2d은(는) %2d번 나왔습니다. | ", i, histogram[i]);

		for (j = 0; j < histogram[i]; j++)
			printf("=");

		puts("");
	}
}