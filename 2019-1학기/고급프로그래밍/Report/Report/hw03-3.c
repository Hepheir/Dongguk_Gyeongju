int hw03_2_GCD(int a, int b); // hw03-2.c
int hw03_3_LCM(int a, int b);

void hw03_3() {
	int a, b;
	a = 20;
	b = 30;
	printf("LCM(%d, %d) = %d\n", a, b, hw03_3_LCM(a, b));
}

int hw03_3_LCM(int a, int b) {
	return a * b / hw03_2_GCD(a, b);
}