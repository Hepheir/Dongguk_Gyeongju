void hw02_7() {
	int n1, n2;
	int sum;

	printf("두 개의 정수 입력 : ");
	scanf("%d %d", &n1, &n2);

	sum = 0;
	for (int i = n1+1; i < n2; i++)
		sum += i;

	printf("%d와 %d 사이의 값의 합 (두 수 제외) : %d\n", n1, n2, sum);
}