#include <ctype.h>

void hw04_5() {
	char *title[9] = {
		"function",

		"isalnum",
		"isalpha",
		"iscntrl",
		"isdigit",
		"isxdigit",
		"ispunct",
		"isprint",
		"isspace"
	};

	int (*func[8])(int) = {
		isalnum,
		isalpha,
		iscntrl,
		isdigit,
		isxdigit,
		ispunct,
		isprint,
		isspace
	};

	for (int j = 0; j < 9; j++)
		printf("%8s ", title[j]);
	printf("\n");

	for (int i = 0x00; i <= 0x7F; i++) {
		printf("%0#4X     ", i);
		for (int j = 0; j < 8; j++)
			printf("%8d ", (*func[j])(i));
		printf("\n");
	}
}