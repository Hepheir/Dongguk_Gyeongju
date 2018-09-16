#pragma warning ( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>

void Q_444_8_pointer() {
	int i, j;

	int *histogram = malloc(sizeof(int) * 10);

	
	//====// TEST //====//
	// histogram = { 0 };
	// *histogram = { 0 };
	//====// TEST //====//

	///////// init /////////
	for (i = 0; i < 10; i++)
		*(histogram + i) = 0;


	///////// input /////////
	int input;

	for (i = 0; i < 20; i++)
	{
		scanf("%d", &input);
		*(histogram + input) += 1;
	}

	///////// output /////////
	for (i = 0; i < 10; i++)
	{
		printf("%2d은(는) %2d번 나왔습니다. > ", i, histogram[i]);

		for (j = 0; j < *(histogram + i); j++)
			printf("=");

		puts("");
	}
}