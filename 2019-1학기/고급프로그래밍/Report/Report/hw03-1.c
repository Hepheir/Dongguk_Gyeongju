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