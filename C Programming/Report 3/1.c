// CRT SECURE WARNING
#include <stdio.h>

int main(void)
{
    int n;

    printf("4자리 정수 입력: ");
    scanf("%d", &n);

    printf("%10d\n", n);
    printf("%010d\n", n);
    printf("%+010d\n", n);
    printf("%-10d\n", n);

    printf("%10o\n", n);
    printf("%010o\n", n);
    
    printf("%10x\n", n);
    printf("%010x\n", n);

    return 0;
}