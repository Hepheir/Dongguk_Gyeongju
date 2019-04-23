double hw03_1_operation(double x);

void hw03_1() {
	double x, y;
	double max_x, max_y;
	
	x = 0.F;
	max_y = 0.F;

	printf("y(x) = 36x - 2x^2\n");

	do {
		y = hw03_1_operation(x);

		if (y > max_y) {
			max_y = y;
			max_x = x;
		}

		x += 0.001F;
	}
	while (y >= 0.F);

	printf("\t[Max @ (%lf, %lf)]\n", max_x, max_y);
}

double hw03_1_operation(double x) {
	double y;
	y = 36 * x - 2 * (x*x);
	printf("\r>>> y(%6.2lf) = %.2lf", x, y);
	return y;
}