#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Q1();
int Q2();
int Q3();
int Q4();

int R1();
int R2();
int R3();
int R3_var();

int S1();
int S2();
int S3();

int T1();
int T2();
int T3();
int T4();
int T5();

int main() {
	R3_var();
}

///////////////////////////////////////

int Q1() {
	int sum = 0;

	for (int i = 1; i <= 100; i++)
		sum += i;

	printf("1�������� 100������ �� : %d\n", sum);

	system("pause");

	return 0;
}

int Q2() {
	int n;
	int sum = 0;

	printf("���� ���� N�� �Է� : ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		sum += i;

	printf("1�������� %d������ �� : %d\n", n, sum);

	system("pause");

	return 0;
}

int Q3() {
	int start, end;

	int sum = 0;

	printf("���� ���� (start, end)�� �Է� : ");
	scanf("%d %d", &start, &end);

	for (int i = start; i <= end; i++)
		sum += i;

	printf("%d�������� %d������ �� : %d\n", start, end, sum);

	system("pause");

	return 0;
}

int Q4() {
	int year;

	printf("�⵵�� �Է� : ");
	scanf("%d", &year);

	switch ((year - 4) % 12) {
	case 0: // ��
		printf("��");
		break;
	case 1: // ��
		printf("��");
		break;
	case 2: // ��
		printf("ȣ����");
		break;
	case 3: // ��
		printf("�䳢");
		break;
	case 4: // ��
		printf("��");
		break;
	case 5: // ��
		printf("��");
		break;
	case 6: // ��
		printf("��");
		break;
	case 7: // ��
		printf("��");
		break;
	case 8: // ��
		printf("������");
		break;
	case 9: // ��
		printf("��");
		break;
	case 10: // ��
		printf("��");
		break;
	case 11: // ��
		printf("����");
		break;
	}

	puts("!");

	system("pause");

	return 0;
}

///////////////////////////////////////

int R1() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < i; j++)
			printf("*");

		puts("");
	}

	system("pause");

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j < i * 2; j++)
			printf("*");

		puts("");
	}

	system("pause");

	for (int i = 4; i >= 1; i--) {
		for (int j = 1; j < i * 2; j++)
			printf("*");

		puts("");
	}

	system("pause");

	for (int i = 5; i >= 1; i--) {
		for (int j = 1; j <= i; j++)
			printf("*");

		puts("");
	}

	system("pause");
	
	int i, j;

	for (i = 1; i < 4; i++) {
		for (j = 1; j <= i; j++)
			printf("*");

		puts("");
	}

	for (; i > 0; i--) {
		for (j = 1; j <= i; j++)
			printf("*");

		puts("");
	}

	system("pause");

	return 0;
}

int R2() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 5; j >= i; j--)
			printf("%d", j);

		puts("");
	}

	return 0;
}

int R3() {
	int num;

	printf("������ ���ڸ� �Է� : ");
	scanf("%d", &num);

	while (num > 0) {
		printf("%d", num % 10);
		num /= 10;
	}

	puts("");
	system("pause");

	return 0;
}

int R3_var() {
	char string[20];

	printf("������ ���ڿ��� �Է� : ");
	scanf("%s", string);

	int eof; // End of File

	for (eof = 0; string[eof] != '\0'; eof++);

	printf("���ڿ��� ���� : %d\n", eof);


	printf("������ ���ڿ� : ");

	for (int i = eof - 1; i >= 0; i--) {
		printf("%c", string[i]);
	}

	puts("");
	system("pause");

	return 0;
}

///////////////////////////////////////

int S_arr[6] = { 0 }; // `S_arr` is used in `S1()`, `S2()`.

int S1() {

	for (int i = 0; i < 6; i++) {
		printf("%d��° �� �Է� : ", i + 1);
		scanf("%d", &S_arr[i]);
	}

	int sum = 0;
	for (int i = 0; i < 6; i++)
		sum += S_arr[i];

	printf("�迭�� �� �� : %d\n", sum);
	printf("�迭�� ��� : %f\n", (float) sum / 6);

	system("pause");
	return 0;
}

int S2() {
	S1();

	int min_index = 0;
	int max_index = 0;

	for (int i = 0; i < 6; i++) {
		if (S_arr[min_index] > S_arr[i])
			min_index = i;
		if (S_arr[max_index] < S_arr[i])
			max_index = i;
	}

	printf("�ִ밪 : %d\n", S_arr[max_index]);
	printf("�ּڰ� : %d\n", S_arr[min_index]);

	system("pause");
	return 0;
}

int S3() {
	float fah, cel;

	printf("�����µ��� ��ȯ�� 'ȭ���µ�' �Է� : ");
	scanf("%f", &fah);

	cel = (fah - 32) * 5 / 9;
	printf("�����µ��� %f�� �Դϴ�.\n", cel);

	system("pause");
	return 0;
}

///////////////////////////////////////

int T_arr[10] = { 0 }; // `T_arr` is used in `T1()`, `T2()`.


int T1() {
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		printf("%d��° �� �Է� : ", i + 1);
		scanf("%d", &T_arr[i]);

		sum += T_arr[i];
	}

	printf("�迭�� �� �� : %d\n", sum);
	printf("�迭�� ��� : %f\n", (float)sum / 10);

	system("pause");
	return 0;
}

int T2() {
	T1();

	int min_index = 0;
	int max_index = 0;

	for (int i = 0; i < 10; i++) {
		if (T_arr[min_index] > T_arr[i])
			min_index = i;
		if (T_arr[max_index] < T_arr[i])
			max_index = i;
	}

	printf("�ִ밪 : %d\n", T_arr[max_index]);
	printf("�ּڰ� : %d\n", T_arr[min_index]);

	system("pause");
	return 0;
}

int T3() {
	char string[26];
	char c = 'Z';

	for (int i = 0; i < 26; i++) {
		string[i] = c - i;
	}

	printf("Z���� A���� ��� : ");;

	for (int i = 0; i < 26; i++) {
		printf("%c", string[i]);
	}
	
	puts("");
	system("pause");

	return 0;
}

int T4() {
	int hist[10];

	int input;

	for (int i = 0; i < 20; i++) {
		printf("%d��° ���� �Է� : ", i + 1);
		
		do {
			scanf("%d", &input);
		} while ( !(0 <= input && input <= 9) );

		hist[input]++;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d�� �Էµ� Ƚ�� : %d��\n", i, hist[i]);
	}

	puts("");
	system("pause");

	return 0;
}

int T5() {
	int score[4][4] = {
		{ 10, 20, 30, 40 },
		{ 11, 21, 31, 41 },
		{ 12, 22, 31, 42 },
		{ 13, 23, 33, 43 }
	};

	int sum;

	for (int student = 0; student < 4; student++) {
		sum = 0;
		for (int i = 0; i < 4; i++)
			sum += score[student][i];

		printf("�л�%d�� ����\n", student + 1);
		printf("\t���� : %d\n", sum);
		printf("\t��� : %d\n", (float) sum / 4);
		puts("");
	}

	puts("");
	system("pause");

	return 0;
}