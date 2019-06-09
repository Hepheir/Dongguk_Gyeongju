#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int hw03_1_operation(int x);

void hw03_1() {
	int x, y;
	int max_x, max_y;
	
	x = 0;
	max_y = 0;

	printf("y(x) = 36x - 2x^2\n");

	do {
		y = hw03_1_operation(x);

		if (y > max_y) {
			max_y = y;
			max_x = x;
		}
		x++;
	}
	while (y >= 0);

	printf("\n[Max @ (%d, %d)]\n", max_x, max_y);
}

int hw03_1_operation(int x) {
	int y = 36 * x - 2 * (x*x);
	printf("\r>>> y(%d) = %d", x, y);
	return y;
}

int GCD(int a, int b);

void hw03_2() {
	int a, b;
	a = 8;
	b = 10;
	printf("GCD(%d, %d) = %d\n", a, b, GCD(a, b));
}

int GCD(int a, int b) {
	int r = a % b;
	if (!r) {
		return b;
	}
	return GCD(b, r);
}

// hw03-2.c
int LCM(int a, int b);

void hw03_3() {
	int a, b;
	a = 8;
	b = 10;
	printf("LCM(%d, %d) = %d\n", a, b, LCM(a, b));
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}

// hw03-4
float x(int t);
float y(int t);

void hw03_4() {
	int t;
	int t_delay = 0;

	unsigned char wasYfaster = 0; // Boolean
	unsigned char isYfaster = 0; // Boolean
	unsigned char isYOvertake = 0; // Boolean

	int overtakes = 0;

	for (t = 0; t <= 60; t++) {
		isYfaster = y(t) > x(t - t_delay);

		isYOvertake = isYfaster && !wasYfaster;

		if (isYOvertake)
			overtakes++;

		printf("[%2d] x: %7.2f, y: %7.2f, overtakes: %d\n",
			t,
			x(t - t_delay),
			y(t),
			overtakes);

		if (t && (t % 15 >= 10)) // Waiting trigger.
			t_delay++;

		wasYfaster = isYfaster;
	}
}

float x(int t) {
	return 3.6F * t;
}

float y(int t) {
	return 2.5F * t;
}

// hw03-5
#define g 9.8F

float v(float t);
float d(float t);

void hw03_5() {
	for (float t = 0.F; t <= 60.F; t += 1.0F) {
		printf("[%.0f��]\tv=%f, \td=%f\n", t, v(t), d(t));
	}
}

float v(float t) {
	return g * t;
}

float d(float t) {
	return 0.5F * v(t) * t;
}

//hw03-6

typedef struct intPoint {
	int x;
	int y;
} Point_i4;

double slope_i4(Point_i4 a, Point_i4 b);
double intercept_i4(Point_i4 a, Point_i4 b);

void hw03_6() {
	Point_i4 a, b;

	printf("x1, y1, x2, y2�� ���ʴ�� �Է� : ");
	scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);

	printf("������ ������ : y = (%.2lf)x + (%.2lf)\n",
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

// hw03-7

typedef struct doublePoint {
	double x;
	double y;
} Point_d8;

Point_d8* input();
Point_d8 intersectionPoint(Point_d8 points[4]);
double slope_d8(Point_d8 a, Point_d8 b);
double intercept_d8(Point_d8 a, Point_d8 b);

void hw03_7() {
	printf("���� AB��, ���� CD�� ���� ���ϱ�.\n");

	Point_d8* points = input();

	printf("%lf %lf\n", (*points).x, (*points).y);

	Point_d8 intersect = intersectionPoint(points);

	printf("%lf %lf\n", (*points).x, (*points).y);

	printf("������ ��ǥ : (%.2lf, %.2lf)\n",
		intersect.x, intersect.y);
}

Point_d8* input() {
	Point_d8 points[4];

	for (int i = 0; i < 4; i++) {
		printf("�� %c�� ��ǥ �Է� (x, y) : ", 'A' + i);
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

// hw03-8
#define g 9.8F

void hw03_8() {
	double t0 = sqrt(128 / g);

	printf("��ü�� %.4lf���� ���鿡 ��´�.\n", t0);
}

// hw03-9
typedef struct time {
	int h;
	int m;
} Time;

Time parkTime(Time inTime, Time outTime);
int parkFee(Time pTime);

void hw03_9() {
	Time in, out;

	printf("�����ð� (h, m) : ");
	scanf("%d %d", &in.h, &in.m);

	printf("�����ð� (h, m) : ");
	scanf("%d %d", &out.h, &out.m);

	printf("������� : %d\n", parkFee(parkTime(in, out)));
}

Time parkTime(Time inTime, Time outTime) {
	Time p;

	int in = inTime.h * 60 + inTime.m;
	int out = (outTime.h * 60 + outTime.m);

	int park = out - in;

	p.h = park / 60;
	p.m = park % 60;

	return p;
}

int parkFee(Time pTime) {
	int t_min = pTime.h * 60 + pTime.m;
	int t = (t_min % 10) ? (t_min / 10 + 1) : (t_min / 10);
	return t * 1000;
}

// hw03-10

void hw03_10() {
	srand(time(NULL));

	int m;
	int k = rand() % 40 + 11; // 11~50

	printf("���ڸ� �Է� (0:����) : ");

	while (1) {
		printf(">>> ");
		scanf("%d", &m);

		if (m == 0) {
			printf("�����մϴ�.\n");
			break;
		}

		if (m == k) {
			printf("�¾���.\n");
			break;
		}

		printf("[%d] -> ", m);
		if (abs(k - m) < 10) {
			printf("���� ");
		}
		else {
			printf("���� ");
		}

		if (k < m) {
			printf("�۰�");
		}
		else {
			printf("ũ��");
		}
		printf("\n");
	}
}

// hw03-11

int factorial(int x);
double bern(double p, int n, int x);

void hw03_11() {
	double p;
	int n;

	printf("������ Ȯ�� (0 < p < 1) : ");
	scanf("%lf", &p);
	printf("���� Ƚ�� (0 < n) : ");
	scanf("%d", &n);

	printf("��� 1�� ��� Ȯ�� : %.5lf\n",
		1 - bern(p, n, 0)
	);
	printf("���ƾ� 3�� ��� Ȯ�� : %.5lf\n",
		bern(p, n, 0)
		+ bern(p, n, 1)
		+ bern(p, n, 2)
		+ bern(p, n, 3)
	);
}

int factorial(int x) {
	if (x == 0)
		return 1;
	return x * factorial(x - 1);
}

double bern(double p, int n, int x) {
	double b = pow(p, x) * pow(1 - p, n - x);
	double nx = factorial(n) / (double)(factorial(x) * factorial(n - x));
	return b * nx;
}