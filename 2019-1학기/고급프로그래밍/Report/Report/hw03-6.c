#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct intPoint {
	int x;
	int y;
} Point_i4;

double slope_i4(Point_i4 a, Point_i4 b);
double intercept_i4(Point_i4 a, Point_i4 b);

void hw03_6() {
	Point_i4 a, b;

	printf("x1, y1, x2, y2를 차례대로 입력 : ");
	scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);

	printf("직선의 방정식 : y = (%.2lf)x + (%.2lf)\n",
		slope_i4(a, b),
		intercept_i4(a, b));
}

double slope_i4(Point_i4 a, Point_i4 b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;

	return dy / dx;
}

double intercept_i4(Point_i4 a, Point_i4 b) {
	return a.y - slope_i4(a, b) * a.x;
}