#include <stdio.h>
#include <conio.h>

int main(void)
{
    char ch;
    
    printf(" ch = %c\n", ch); // !
    printf("&ch = %u\n", &ch); // !

    printf("문자를 계속 입력하고 Enter를 누르면 >>\n");
    while ((ch = getchar()) != 'q')
        putchar(ch);
    
    printf("\n");
    printf(" ch = %c\n", ch); // !
    printf("&ch = %u\n", &ch); // !


    printf("\n문자를 계속 입력하고 Enter를 누르면 >>\n");
    while ((ch = _getche()) != 'q')
        putchar(ch);
    
    printf("\n");
    printf(" ch = %c\n", ch); // !
    printf("&ch = %u\n", &ch); // !

    printf("\n문자를 계속 입력하고 Enter를 누르면 >>\n");
    while ((ch = _getch()) != 'q')
        _putch(ch);
    printf("\n");

    printf(" ch = %c\n", ch); // !
    printf("&ch = %u\n", &ch); // !

    return 0;
}