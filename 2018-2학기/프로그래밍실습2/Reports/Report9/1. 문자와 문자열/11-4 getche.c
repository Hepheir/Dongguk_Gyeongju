#include <stdio.h>
#include <conio.h>

int main(void)
{
    char ch;
    
    printf(" ch = %c\n", ch); // !
    printf("&ch = %u\n", &ch); // !

    printf("���ڸ� ��� �Է��ϰ� Enter�� ������ >>\n");
    while ((ch = getchar()) != 'q')
        putchar(ch);
    
    printf("\n");
    printf(" ch = %c\n", ch); // !
    printf("&ch = %u\n", &ch); // !


    printf("\n���ڸ� ��� �Է��ϰ� Enter�� ������ >>\n");
    while ((ch = _getche()) != 'q')
        putchar(ch);
    
    printf("\n");
    printf(" ch = %c\n", ch); // !
    printf("&ch = %u\n", &ch); // !

    printf("\n���ڸ� ��� �Է��ϰ� Enter�� ������ >>\n");
    while ((ch = _getch()) != 'q')
        _putch(ch);
    printf("\n");

    printf(" ch = %c\n", ch); // !
    printf("&ch = %u\n", &ch); // !

    return 0;
}