#include <stdio.h>

int main(void)
{
    int month;

    scanf("%d", &month);

    (month > 6) ? printf("하") : printf("상");
    
    printf("반기입니다.\n");

    return 0;
}