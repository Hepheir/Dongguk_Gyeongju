void hw02_7() {
	int n1, n2;
	int sum;

	printf("�� ���� ���� �Է� : ");
	scanf("%d %d", &n1, &n2);

	sum = 0;
	for (int i = n1+1; i < n2; i++)
		sum += i;

	printf("%d�� %d ������ ���� �� (�� �� ����) : %d\n", n1, n2, sum);
}