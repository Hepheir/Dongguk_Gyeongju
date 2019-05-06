int includes(int A[], int sizeofA, int element);
void unionSet(int A[], int sizeofA, int B[], int sizeofB);
void intersectionSet(int A[], int sizeofA, int B[], int sizeofB);
void printSet(int A[], int sizeofA);

void hw04_4() {
	int A[4] = { 1, 3, 5, 7 };
	int B[5] = { 3, 5, 8, 9, 11 };

	printf("����A=");
	printSet(A, 4);
	printf("\n");

	printf("����B=");
	printSet(B, 5);
	printf("\n");

	printf("\n");

	printf("�� ������ �������� ���\n");
	unionSet(A, 4, B, 5);
	printf("\n");

	printf("�� ������ �������� ���\n");
	intersectionSet(A, 4, B, 5);
	printf("\n");
}

int includes(int A[], int sizeofA, int element) {
	for (int i = 0; i < sizeofA; i++)
		if (A[i] == element)
			return 1;
	return 0;
}

void unionSet(int A[], int sizeofA, int B[], int sizeofB) {
	int C[10];
	int sizeofC = 0;

	for (int i = 0; i < sizeofA; i++)
		C[sizeofC++] = A[i];

	for (int i = 0; i < sizeofB; i++)
		if (!includes(A, sizeofA, B[i]))
			C[sizeofC++] = B[i];

	printf("A��B=");
		printSet(C, sizeofC);
	printf("\n");
}

void intersectionSet(int A[], int sizeofA, int B[], int sizeofB) {
	int C[10];
	int sizeofC = 0;

	for (int i = 0; i < sizeofA; i++)
		if (includes(B, sizeofB, A[i]))
			C[sizeofC++] = A[i];

	printf("A��B=");
		printSet(C, sizeofC);
	printf("\n");
}

void printSet(int A[], int sizeofA) {
	printf("{");
	for (int i = 0; i < sizeofA; i++) {
		printf("%d", A[i]);
		if (i+1 < sizeofA)
			printf(", ");
	}
	printf("}");
}