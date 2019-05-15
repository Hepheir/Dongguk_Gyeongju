char *string_cpy(char *dest, const char *src);

void hw05_2() {
	char str[20];
	char *pt;
	pt = string_cpy(str, "my program");
	printf("str : %s\n", str);
	printf("pt : %s\n", pt);
}

char *string_cpy(char *dest, const char *src) {
	char *p = dest;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return dest;
}