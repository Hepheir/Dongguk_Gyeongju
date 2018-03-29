#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int * getLine(void);

int main(void)
{
	int N, groups, i , j, chainedWithGroup;
	scanf("%d", &N);

	int** lines = malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++)
		*(lines + i) = getLine();

	for (i = 0; i < N - 1; i++)
	{
		chainedWithGroup = 0;
		for (j = i + 1; j < N; j++)
		{
			if ( && !chainedWithGroup)
			{
				chainedWithGroup = groups++;
			}
		}
	}
		

	return 0;
}

int * getLine(void)
{
	int * line = malloc(sizeof(int) * 5); // 5번째 공간에는 이 선분이 속한 그룹 정보 저장

	// X1, Y1, X2, Y2 순서로 입력받음
	for (int i = 0; i < 4; i++)
		scanf("%d", line + i);

	return line;
}

int * getGroup(int* line)
{
	
}

int isIntersect(int* line1, int* line2)
{
	int x1, y1, x2, y2; // A-B
	int a1, b1, a2, b2; // C-D

	// D-B slope
	float deltaBD = () / ()

}