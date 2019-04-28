#define g 9.8F

float v(float t);
float d(float t);

void hw03_5() {
	for (float t = 0.F; t <= 60.F; t += 1.0F) {
		printf("v=%f, d=%f\n", v(t), d(t));
	}
}

float v(float t) {
	return g * t;
}

float d(float t) {
	return 0.5F * v(t) * t;
}