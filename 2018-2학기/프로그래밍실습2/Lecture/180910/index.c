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

	printf("1에서부터 100까지의 합 : %d\n", sum);

	system("pause");

	return 0;
}

int Q2() {
	int n;
	int sum = 0;

	printf("양의 정수 N을 입력 : ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		sum += i;

	printf("1에서부터 %d까지의 합 : %d\n", n, sum);

	system("pause");

	return 0;
}

int Q3() {
	int start, end;

	int sum = 0;

	printf("양의 정수 (start, end)를 입력 : ");
	scanf("%d %d", &start, &end);

	for (int i = start; i <= end; i++)
		sum += i;

	printf("%d에서부터 %d까지의 합 : %d\n", start, end, sum);

	system("pause");

	return 0;
}

int Q4() {
	int year;

	printf("년도를 입력 : ");
	scanf("%d", &year);

	switch ((year - 4) % 12) {
	case 0: // 자
		printf("쥐");
		break;
	case 1: // 축
		printf("소");
		break;
	case 2: // 인
		printf("호랑이");
		break;
	case 3: // 묘
		printf("토끼");
		break;
	case 4: // 진
		printf("용");
		break;
	case 5: // 사
		printf("뱀");
		break;
	case 6: // 오
		printf("말");
		break;
	case 7: // 미
		printf("양");
		break;
	case 8: // 신
		printf("원숭이");
		break;
	case 9: // 유
		printf("닭");
		break;
	case 10: // 술
		printf("개");
		break;
	case 11: // 해
		printf("돼지");
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

	printf("뒤집을 숫자를 입력 : ");
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

	printf("뒤집을 문자열을 입력 : ");
	scanf("%s", string);

	int eof; // End of File

	for (eof = 0; string[eof] != '\0'; eof++);

	printf("문자열의 길이 : %d\n", eof);


	printf("뒤집은 문자열 : ");

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
		printf("%d번째 값 입력 : ", i + 1);
		scanf("%d", &S_arr[i]);
	}

	int sum = 0;
	for (int i = 0; i < 6; i++)
		sum += S_arr[i];

	printf("배열의 총 합 : %d\n", sum);
	printf("배열의 평균 : %f\n", (float) sum / 6);

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

	printf("최대값 : %d\n", S_arr[max_index]);
	printf("최솟값 : %d\n", S_arr[min_index]);

	system("pause");
	return 0;
}

int S3() {
	float fah, cel;

	printf("섭씨온도로 변환할 '화씨온도' 입력 : ");
	scanf("%f", &fah);

	cel = (fah - 32) * 5 / 9;
	printf("섭씨온도로 %f도 입니다.\n", cel);

	system("pause");
	return 0;
}

///////////////////////////////////////

int T_arr[10] = { 0 }; // `T_arr` is used in `T1()`, `T2()`.


int T1() {
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		printf("%d번째 값 입력 : ", i + 1);
		scanf("%d", &T_arr[i]);

		sum += T_arr[i];
	}

	printf("배열의 총 합 : %d\n", sum);
	printf("배열의 평균 : %f\n", (float)sum / 10);

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

	printf("최대값 : %d\n", T_arr[max_index]);
	printf("최솟값 : %d\n", T_arr[min_index]);

	system("pause");
	return 0;
}

int T3() {
	char string[26];
	char c = 'Z';

	for (int i = 0; i < 26; i++) {
		string[i] = c - i;
	}

	printf("Z부터 A까지 출력 : ");;

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
		printf("%d번째 원소 입력 : ", i + 1);
		
		do {
			scanf("%d", &input);
		} while ( !(0 <= input && input <= 9) );

		hist[input]++;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d가 입력된 횟수 : %d번\n", i, hist[i]);
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

		printf("학생%d의 성적\n", student + 1);
		printf("\t총합 : %d\n", sum);
		printf("\t평균 : %d\n", (float) sum / 4);
		puts("");
	}

	puts("");
	system("pause");

	return 0;
}