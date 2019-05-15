void vice_versa(char *src);

void hw05_6() {
	char chr[40];

	printf("String to swap : ");
	gets(chr);
	
	printf("Before swap : %s\n", chr);
	vice_versa(chr);
	printf("After swap : %s\n", chr);
}

void vice_versa(char *src) {
	int len = 0;

	while (*(src+len))
		len++;

	char temp;
	for (int i = 0; i < (len - i); i++) {
		temp = src[i];
		src[i] = src[len - i - 1];
		src[len - i - 1] = temp;
	}
}