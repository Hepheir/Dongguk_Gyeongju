int my_strcmp(const char *str1, const char *str2);
void my_strcpy(char* dest, const char* src);

void hw05_9() {
	char a[] = "Welcome to C Programming !";
	char b[] = "Welcome to C World !";

	printf("a : %s\nb : %s\n", a, b);

	printf("my_strcmp(a,b) : %d\n", my_strcmp(a, b));
	my_strcpy(a, b);
	printf("my_strcpy(a,b) >>> a : %s\n", a);
}

int my_strcmp(const char *str1, const char *str2) {
	while (*str1) {
		if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
			return -1;

		str1++; str2++;
	}

	if (*str2  == '\0')
		return 0;
	else
		return -1; // str2가 크므로
}

void my_strcpy(char* dest, const char* src) {
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}