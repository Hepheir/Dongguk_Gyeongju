#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    
    printf("   &i = %u\n", &i); // !
    printf("&argc = %u\n", &argc); // !
    printf(" argv = %u\n", argv); // !

    printf("���� ����� ����(command line arguments) >>\n");
    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);

    return 0;
}