#include <stdio.h>
#include <string.h>

int main (void) {
    char dest[80] = "C";
    printf("dest = %u\n", dest); // !

    printf("%s\n", strcat(dest, " is "));
    printf("%s\n", strncat(dest, "a java", 2));
    printf("%s\n", strcat(dest, "procedural "));
    printf("%s\n", strcat(dest, "language."));
    
    printf("dest = %u\n", dest); // !

    return 0;
}