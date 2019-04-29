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