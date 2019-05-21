int plus(int x, int y);

void hw05_1() {
	int(*pt) (int a, int b);
	int a = 3, b = 5;
	pt = plus;
	printf("result = %d\n", pt(a, b));
	printf("result = %d\n", plus(a, b));
}

int plus(int x, int y) {
	return x + y;
}
