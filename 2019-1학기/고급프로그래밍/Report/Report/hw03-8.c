#include <math.h>
#define g 9.8F

void hw03_8() {
	double t0 = sqrt(128 / g);

	printf("물체는 %.4lf에서 지면에 닿는다.\n", t0);
}