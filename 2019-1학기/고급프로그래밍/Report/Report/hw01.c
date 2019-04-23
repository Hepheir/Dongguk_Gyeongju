#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

void hw01_1() {
	float x, y;
	float a, b, c;

	a = 2.5F;
	b = 3.2F;
	c = 4.5F;
	
	x = 10.5F;

	y = (a - b)*(x*x) + (b - c)*x - 20 * a*c;

	printf("y=(a-b)*(x*x)+(b-c)*x-20*a*c\n");
	printf("�� ����� : %f\n", y);
	return;
}

void hw01_2() {
	typedef struct vehicle {
		char* name;
		float speed;
	} Vehicle;

	float distance = 75000000;

	Vehicle veh[4] = {
		{ "KTX", 300 },
		{ "������ ����", 11.9 * 3600 },
		{ "�ΰ� �װ���", 850 },
		{ "���ֿ� �ڵ���(F1)", 350 }
	};

	for (int i = 0; i < 4; i++) {
		printf("%s�� ���µ� �ɸ��� �ð� : %.2f\n",
			veh[i].name,
			(distance / veh[i].speed));

		printf("\t�� ���δ� %.2f��\n",
			(distance / veh[i].speed)/(24*365));
	}
	return;
}

void hw01_3() {
	float R;
	float RC_inv = 0;

	for (int i = 0; i < 3; i++) {
		printf("R%d�� �� �Է�: ", i);
		scanf("%f", &R);
		RC_inv += 1 / R;
	}

	printf("ȸ���� �ռ�����(RC)�� : %.2f �Դϴ�.\n", (1 / RC_inv));
	return;	
}

void hw01_4() {
	int A[4];
	int B[4];

	float sol[2]; // Solution (x, y)

	// ��ǥ �Է� { x1, y1, x2, y2 }
	printf("���� A�� �� ���� ��ǥ �Է� (x1, y1, x2, y2) : ");
	for (int i = 0; i < 4; i++)
		scanf("%d", &A[i]);
	printf("���� B�� �� ���� ��ǥ �Է� (x1, y1, x2, y2) : ");
	for (int i = 0; i < 4; i++)
		scanf("%d", &B[i]);

	// ������ ������ ���ϱ� : y=a*x+b
	// ���� : dy/dx = (y1 - y2)/(x1 - x2)
	float dA = (A[1] - A[3]) / (float)(A[0] - A[2]);
	float dB = (B[1] - B[3]) / (float)(B[0] - B[2]);
	// Y ���� b = y - ax
	float A_C = A[1] - dA * A[0];
	float B_C = B[1] - dB * B[0];
	
	if (dA == dB) {
		printf("�� ������ ");
		if (A_C == B_C)
			printf("��ġ");
		else
			printf("����");
		printf("�մϴ�.\n");
		return;
	}

	// ������ X��ǥ ���ϱ� (����) : 0 = (dA - dB)x + (A_C - B_C) --> x = -(A_C - B_C)/(dA - dB) = (B_C - A_C)/(dA - dB)
	sol[0] = (B_C - A_C) / (dA - dB);
	// ������ Y��ǥ ���ϱ� (����)
	sol[1] = dA * sol[0] + A_C;

	// ���
	printf("������ ��ǥ�� (%.2f, %.2f) �Դϴ�.\n", sol[0], sol[1]);
	return;
}

void hw01_5() {
	float watt, volt, ampere, ohm;

	watt = 1300.F;
	volt = 120.F;

	// P=VI --> I=P/V
	ampere = watt / volt;

	// V=IR --> R=V/I
	ohm = volt / ampere;
	printf("������̱��� ������ : %.2f[��] �Դϴ�.\n", ohm);
	return;
}

void hw01_6() {
	int num, den;

	// �������� ���� �Է�
	printf("Input Numerator   : ");
	scanf("%d", &num);

	// �������� �и� �Է�
	printf("Input Denominator : ");
	scanf("%d", &den);

	printf("Results : Quotient=%d, Remainder=%d\n", num/den, num%den);
	return;
}

void hw01_7() {
	unsigned short a = 0xAAAA, b = 0x505F;
	// a = 0b 1010 1010 1010 1010
	// b = 0b 0101 0000 0101 1111
	// �̹Ƿ�,
	// Bitwise ������ ����� ������ ���� ��.
	// a AND b : 0b 0000 0000 0000 1010 = 0xA
	// a OR b  : 0b 1111 1010 1111 1111 = 0xFAFF
	// a XOR b : 0b 1111 1010 1111 0101 = 0xFAF5
	// NOT a   : 0b 0101 0101 0101 0101 = 0x5555
	printf("a = %0X\n", a);
	printf("b = %0X\n", b);

	printf("sizeof a : %d\n", sizeof(a));

	printf("Bitwise (a and b) : 0x%X\n", a & b);

	printf("Sizeof (a and b) : %d\n", sizeof(a & b));

	printf("Bitwise (a or b)  : 0x%X\n", a | b);
	printf("Bitwise (a xor b) : 0x%X\n", a ^ b);
	printf("Bitwise (~a) : 0x%X\n", ~a);

	printf("Sizeof (~a) : %d\n", sizeof(~a));
	return;
}


void hw01_8() {
	int balance;
	int coins[] = { 500, 100, 50, 10 };
	int coins_length = 4;

	printf("�׼��� �Է��Ͻÿ�: ");
	scanf("%d", &balance);

	printf("%d����", balance);
	for (int i = 0; i < coins_length; i++) {
		printf(", %d��¥�� %d��", coins[i], (balance/coins[i]));
		balance %= coins[i];
	}
	printf("�̴�.\n");
	return;
}

void printMatrix(char* units[], double mat[][9], int blockSize) {
	double cell;
	for (int row = 0; row < 9; row++) {
		if (row == 0) {
			printf("%*s ", blockSize, "");
			for (int col = 0; col < 9; col++)
				printf("%*s ", blockSize, units[col]);
			printf("\n");
		}
		printf("1 %-*s ", blockSize, units[row]);
		for (int col = 0; col < 9; col++) {
			cell = mat[row][col];
			if (cell == 1.L)
				printf("%*d ", blockSize, 1);
			else if (cell > 1.L)
				printf("%*.*lf ", blockSize, 2, cell);
			else
				printf("%*.*lf ", blockSize, 8, cell);
		}
		printf("\n");
	}
}

void hw01_9() {
	char *units[9] =
		{ "cm",		"m",	"inch", "feet", "yard", "mile", "ja",	"gan",	"lee" };
	double data_table[9][9] = {
		{ 1,		0,		0,		0,		0,		0,		0,		0,		0 },
		{ 100,		0,		0,		0,		0,		0,		0,		0,		0 },
		{ 2.54,		0,		0,		0,		0,		0,		0,		0,		0 },
		{ 30.48,	0,		0,		0,		0,		0,		0,		0,		0 },
		{ 91.438,	0,		0,		0,		0,		0,		0,		0,		0 },
		{ 160930,	0,		0,		0,		0,		0,		0,		0,		0 },
		{ 30.303,	0,		0,		0,		0,		0,		0,		0,		0 },
		{ 181.818,	0,		0,		0,		0,		0,		0,		0,		0 },
		{ 392727,	0,		0,		0,		0,		0,		0,		0,		0 } };

	int row, col;
	// Calc ratio based a centi meter, and write the ratio in the first row.
	for (row = 1; row < 9; row++)
		data_table[0][row] = 1 / data_table[row][0];

	// Fill the rest of the table
	double cm, ratio;
	for (row = 1; row < 9; row++) {
		cm = data_table[row][0];
		for (col = 1; col < 9; col++) {
			ratio = data_table[0][col];
			data_table[row][col] = cm * ratio;
		}
	}

	printMatrix(units, data_table, 12);
	return;
}

void hw01_10() {
	char *units[9] =
		{ "g",		"kg",	"ton",	"gr",	"oz",	"lb",	"don",	"geun",	"guan" };
	double data_table[9][9] = {
		{ 1,		0,		0,		0,		0,		0,		0,		0,		0 },
		{ 1000,		0,		0,		0,		0,		0,		0,		0,		0 },
		{ 1000000,	0,		0,		0,		0,		0,		0,		0,		0 },
		{ 0.06479,	0,		0,		0,		0,		0,		0,		0,		0 },
		{ 28.3495,	0,		0,		0,		0,		0,		0,		0,		0 },
		{ 453.592,	0,		0,		0,		0,		0,		0,		0,		0 },
		{ 3.75,		0,		0,		0,		0,		0,		0,		0,		0 },
		{ 600,		0,		0,		0,		0,		0,		0,		0,		0 },
		{ 3750,		0,		0,		0,		0,		0,		0,		0,		0 } };

	int row, col;
	// Calc ratio based a centi meter, and write the ratio in the first row.
	for (row = 1; row < 9; row++)
		data_table[0][row] = 1 / data_table[row][0];

	// Fill the rest of the table
	double cm, ratio;
	for (row = 1; row < 9; row++) {
		cm = data_table[row][0];
		for (col = 1; col < 9; col++) {
			ratio = data_table[0][col];
			data_table[row][col] = cm * ratio;
		}
	}

	printMatrix(units, data_table, 12);
	return;
}