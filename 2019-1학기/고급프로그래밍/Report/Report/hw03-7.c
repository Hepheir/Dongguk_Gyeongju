#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct doublePoint {
	double x;
	double y;
} Point_d8;

Point_d8* input();
Point_d8 intersectionPoint(Point_d8 points[4]);
double slope_d8(Point_d8 a, Point_d8 b);
double intercept_d8(Point_d8 a, Point_d8 b);

void hw03_7() {
	printf("직선 AB와, 직선 CD의 교점 구하기.\n");

	Point_d8* points = input();

	printf("%lf %lf\n", (*points).x, (*points).y);

	Point_d8 intersect = intersectionPoint(points);

	printf("%lf %lf\n", (*points).x, (*points).y);

	printf("교점의 좌표 : (%.2lf, %.2lf)\n",
		intersect.x, intersect.y);
}

Point_d8* input() {
	Point_d8 points[4];

	for (int i = 0; i < 4; i++) {
		printf("점 %c의 좌표 입력 (x, y) : ", 'A' + i);
		scanf("%lf %lf", &points[i].x, &points[i].y);
	}

	return points;
}

Point_d8 intersectionPoint(Point_d8 points[4]) {
	printf("%lf %lf\n", (*points).x, (*points).y);
	Point_d8 intersect;

	// ax + b = cx + d
	// (a-c)x = d-b
	// x = d-b / (a-c)
	double a = slope_d8(points[0], points[1]);
	double b = intercept_d8(points[0], points[1]);
	double c = slope_d8(points[2], points[3]);
	double d = intercept_d8(points[2], points[3]);

	intersect.x = (d - b) / (a - c);
	intersect.y = a * intersect.x + b;

	return intersect;
}

double slope_d8(Point_d8 a, Point_d8 b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;

	return dx / dy;
}

double intercept_d8(Point_d8 a, Point_d8 b) {
	return a.y - slope_d8(a, b) * a.x;
}