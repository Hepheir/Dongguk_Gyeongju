void my_strcat(char *dest, const char*src);

void hw05_4() {
	char source[40] = "Hello, ";
	char append[20] = "world!";

	my_strcat(source, append);

	printf("String concat : %s\n", source);
}

void my_strcat(char *dest, const char*src) {
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0'; // NULL
}