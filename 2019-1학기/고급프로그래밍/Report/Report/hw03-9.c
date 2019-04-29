typedef struct time {
	int h;
	int m;
} Time;

Time parkTime(Time inTime, Time outTime);
int parkFee(Time pTime);

void hw03_9() {
	Time in, out;

	printf("입차시간 (h, m) : ");
	scanf("%d %d", &in.h, &in.m);

	printf("출차시간 (h, m) : ");
	scanf("%d %d", &out.h, &out.m);

	printf("주차요금 : %d\n", parkFee(parkTime(in, out)));
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
