#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

union uchr {
	char chr1;
	char chr2[3];
};

void hw07_1() {
	union uchr data;
	strcpy(data.chr2, "AB");
	printf("data.chr1 = %c\n", data.chr1);
	printf("data.chr2 = %s\n", data.chr2);
	data.chr1 = 'C';
	printf("data.chr1 = %c\n", data.chr1);
	printf("data.chr2 = %s\n", data.chr2);
}

// hw07-2
union data {
	char ch;
	int n;
};

int hw07_2() {
	union data v;
	printf("%d\n", sizeof(union data));
	v.ch = 'A';
	printf("%d\n", sizeof(union data));
	v.n = 25;
	printf("%d\n", sizeof(v.n));
	return 0;
}

void hw07_3() {
	//
}

void hw07_4() {
	//
}

void hw07_5() {
	//
}

// hw07-6
struct patient {
	char age;
	unsigned sex : 1;
	unsigned drinking : 1;
	unsigned smoking : 1;
	unsigned marriage : 1;
};

int hw07_6() {
	struct patient a = { 24, 0, 1, 1, 0 };
	printf("age :%d\n", a.age);
	printf("sex : %d\n", a.sex);
	printf("drinking : %d\n", a.drinking);
	printf("smoking : %d\n", a.smoking);
	return 0;
}
/*
(1) ��Ʈ �ʵ� ����ü ���� a�� ũ���?
(2) �� ���α׷��� ���� �����?
(3) ����� �����Ϳ� ���� ������ ���� ��� sex�� 0�̸� "����", 1�̸� "����"��,
	drinking�� 1�̸� "������"��, smoking�� 1�̸� "����",
	marriage�� 1�̸� "��ȥ��"�� ��µǵ��� ���α׷��� �����Ͻÿ�.
*/

//hw07-7
typedef unsigned char BYTE;
typedef unsigned short BYTE_2;

struct student1 {
	BYTE sex : 1;
	BYTE grade : 3;
	BYTE class : 1;
	BYTE major : 4;
	char name[11];
	BYTE hasPC : 1;
};

struct student2 {
	BYTE sex : 1;
	BYTE grade : 3;
	BYTE class : 1;
	BYTE major : 4;
	BYTE hasPC : 1;
	char name[11];
};

struct student3 {
	BYTE_2 sex : 1;
	BYTE_2 grade : 3;
	BYTE_2 class : 1;
	BYTE_2 major : 4;
	BYTE_2 hasPC : 1;
	char name[11];
};

struct student4 {
	unsigned sex : 1;
	unsigned grade : 3;
	unsigned class : 1;
	unsigned major : 4;

	unsigned hasPC : 1;
	char name[11];
};

struct student5 {
	unsigned sex : 1;
	unsigned grade : 3;
	unsigned class : 1;
	unsigned major : 4;
	char name[11];
	unsigned hasPC : 1;
};

struct student6 {
	signed sex : 1;
	signed grade : 3;
	signed class : 1;
	signed major : 4;
	char name[11];
	signed hasPC : 1;
};

void hw07_7() {
	printf("sizeof(struct student1) = %d\n", sizeof(struct student1));
	printf("sizeof(struct student2) = %d\n", sizeof(struct student2));
	printf("sizeof(struct student3) = %d\n", sizeof(struct student3));
	printf("sizeof(struct student4) = %d\n", sizeof(struct student4));
	printf("sizeof(struct student5) = %d\n", sizeof(struct student5));
	printf("sizeof(struct student6) = %d\n", sizeof(struct student6));
	// 14�� ������ ������ Visual Studio�� Ȧ�� ����Ʈ�� ¦���� �о ���ַ��� �ϱ� �����̴�.
	// ���α׷��� ���� ����, ���������� ����� �ȴٸ�, 13�� ���;� ��.
}

// hw07-8
struct customer1 {
	BYTE sex : 1;
	BYTE p_month : 4;
	BYTE room : 2;
	BYTE isAdult : 1;
	// 11bits (1byte + 3bit) --> 2byte
	BYTE_2 p_year : 11; // 2byte
	BYTE_2 genre : 3;
};

struct customer2 {
	BYTE_2 sex : 1;
	BYTE_2 p_year : 11;
	BYTE_2 p_month : 4;
	// 16bits = 2bytes
	BYTE_2 genre : 3;
	BYTE_2 room : 2;
	BYTE_2 isAdult : 1;
	// 22bits
};

struct customer3 {
	BYTE_2 sex : 1;
	BYTE_2 p_year : 11;
	BYTE_2 p_month : 4;
	// 16bits == 2bytes
	BYTE genre : 3;
	BYTE room : 2;
	BYTE isAdult : 1;
	// 6bits ==> 8bits 1 byte
};

struct customer {
	unsigned sex : 1;
	unsigned p_year : 11;
	unsigned p_month : 4;
	unsigned genre : 3;
	unsigned room : 2;
	unsigned isAdult : 1;
	// 22 bits
};

void hw07_8() {
	printf("sizeof(struct customer1) = %d\n", sizeof(struct customer1));
	printf("sizeof(struct customer2) = %d\n", sizeof(struct customer2));
	printf("sizeof(struct customer3) = %d\n", sizeof(struct customer3));
	printf("sizeof(struct customer) = %d\n", sizeof(struct customer));
}

void hw07_9() {
	struct patient {
		char *name;
		unsigned dr : 1;
		unsigned sm : 1;
	};
	
	struct patient data[4] = {
		{"Kim", 0, 0},
		{"Choi", 0, 1},
		{"Park", 1, 0},
		{"Lee", 1, 1}
	};

	int i;
	for (i = 0; i < 4; i++) {
		printf("1. �� �� �ϰ� �ִ� ȯ��\n");
		if (data[i].dr * data[i].sm)
			printf("%s\n", data[i].name);

		if (data[i].dr && data[i].sm)
			printf("%s\n", data[i].name);


		printf("2. �� �� ���� �ʴ� ȯ��\n");
		if (!data[i].dr * !data[i].sm)
			printf("%s\n", data[i].name);


		printf("3. �� ������ �ϴ� ȯ��\n");
		if (data[i].dr - data[i].sm)
			printf("%s\n", data[i].name);


		printf("4. �� ���� �̻� �ϴ� ȯ��\n");
		if (data[i].dr + data[i].sm)
			printf("%s\n", data[i].name);

		if (data[i].dr || data[i].sm)
			printf("%s\n", data[i].name);


		printf("5. ���� �ϴ� ȯ��\n");
		if (data[i].sm)
			printf("%s\n", data[i].name);


		printf("6. ���� ���� �ʴ� ȯ��\n");
		if (!data[i].sm)
			printf("%s\n", data[i].name);


		printf("7. ��� �� ������ ���� �ʴ� ȯ��\n");
		if (data[i].dr * data[i].sm - 1)
			printf("%s\n", data[i].name);

		if (!data[i].dr || !data[i].sm)
			printf("%s\n", data[i].name);
	}
}


union bank_account {
	char A[8];
	char B[11];
	char C[13];
};

void printRecord(union bank_account income, union bank_account outcome, int deposit);

void hw07_10() {
	union bank_account income, outcome;
	int balance;

	printf("��� ���¹�ȣ �Է� : ");
	scanf("%s", outcome.C);
	printf("�Ա� ���¹�ȣ �Է� : ");
	scanf("%s", income.C);
	printf("�ű� �ݾ� �Է� : ");
	scanf("%d", &balance);
}

char bank_name(union bank_account acc) {
	switch (strlen(acc.C))
	{
	case 7:
		return 'A';
	case 10:
		return 'B';
	case 12:
		return 'C';
	default:
		return 0;
	}
}

void printRecord(union bank_account income, union bank_account outcome, int deposit) {
	printf("%5s %15s %10s\n", "����", "���¹�ȣ", "�ݾ�");
	printf("�Ա� ���� : %s \t");
}