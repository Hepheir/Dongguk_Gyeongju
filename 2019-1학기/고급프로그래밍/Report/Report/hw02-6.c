void hw02_6() {
	int po2, po3; // product of 2 and 3
	po2 = 0; po3 = 0;

	for (int i = 1; i <= 100; i++) {
		if (i % 2 == 0) po2 += i;
		if (i % 3 == 0) po3 += i;
	}

	printf("2�� ����� �� : %d\n", po2);
	printf("3�� ����� �� : %d\n", po3);
	printf("2, 3�� ����� �յ��� ���� %d �Դϴ�.\n", po2 - po3);
}