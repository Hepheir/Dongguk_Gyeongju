int hw03_2_GCD(int a, int b);

void hw03_2() {
	int a, b;
	a = 20;
	b = 30;
	printf("GCD(%d, %d) = %d\n", a, b, hw03_2_GCD(a,b));
}

int hw03_2_GCD(int a, int b) {
	int r = a % b;
	if (!r) {
		return b;
	}
	return hw03_2_GCD(b, r);
}