#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "C and C++\t language are best!";
    char *delimiter = " ,\t!";

    printf("str1 = %u\n", str1); // !
    printf("delimiter = %u\n", delimiter); // !

    printf("���ڿ� \"%s\"�� >>\n", str1);
    printf("������[%s]�� �̿��Ͽ� ��ū�� ���� >>\n", delimiter);
    char *ptoken = strtok(str1, delimiter);
    
    printf("ptoken = %u\n", ptoken); // !

    while (ptoken != NULL)
    {
        printf("%s\n", ptoken);
        ptoken = strtok(NULL, delimiter);
    }
    return 0;
}