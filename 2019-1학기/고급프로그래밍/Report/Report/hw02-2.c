void hw02_2() {
	int itemNum, quantity, price;

	printf("품명번호와 수량을 입력하세요 : ");
	scanf("%d %d", &itemNum, &quantity);

	switch (itemNum) {
	case 1:
		printf("Monitor");
		price = 192000;
		break;
	case 2:
		printf("Hard Disk");
		price = 85000;
		break;
	case 3:
		printf("CPU");
		price = 156000;
		break;
	case 4:
		printf("Mother Board");
		price = 206000;
		break;
	case 5:
		printf("Keyboard");
		price = 28500;
		break;
	case 6:
		printf("mouse");
		price = 14000;
		break;
	default:
		printf("ERROR! - Wrong item number\n");
		price = 0;
	}

	printf(" *%d, %d(원)\n", quantity, price*quantity);
}