#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "C and C++\t language are best!";
    char *delimiter = " ,\t!";
    // char *next_token; //�Լ� strtok_s()�� ���

    printf("���ڿ� \"%s\"�� >>\n", str1);
    printf("������[%s]�� �̿��Ͽ� ��ū�� ���� >> \n", delimiter);
    char *ptoken = strtok(str1, delimiter);
    // char *ptoken = strtok_s(str1, delimiter, &next_token); //�Լ� strtok_s()�� ���
    while ( ptoken != NULL )
    {
        printf("%s\n", ptoken);
        ptoken = strtok(NULL, delimiter);
        // ptoken = strtok_s(NULL, delimiter, &next_token); // ���� ��ū�� ��ȯ
    }

    return 0;
}