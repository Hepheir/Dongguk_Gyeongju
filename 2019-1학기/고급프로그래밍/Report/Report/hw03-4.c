float x(int t);
float y(int t);

void hw03_4() {
	int t;
	int t_delay = 0;

	unsigned char wasYfaster = 0; // Boolean
	unsigned char isYfaster = 0; // Boolean

	int cnt = 0;

	for (t = 0; t <= 60; t++) {
		isYfaster = y(t) > x(t - t_delay);

		if (isYfaster && !wasYfaster)
			cnt++;

		wasYfaster = isYfaster;
		printf("[%2d] x: %7.2f, y: %7.2f, cnt: %d\n", t, x(t - t_delay), y(t), cnt);

		if (t && (t % 15 >= 10)) // Waiting trigger.
			t_delay++;
	}
}

float x(int t) {
	return 3.6F * t;
}

float y(int t) {
	return 2.5F * t;
}