#include <stdio.h>


int main(void)
{
    int n;
    int sum = 0;

    for (n = 1; sum + n <= 10000; n++)
    {
        sum = sum + n;
    }

    printf("1���� n������ �� �߿��� 10000�� ���� �ʴ� ���� ū �� : %d\n", sum);
    printf("�� ���� n : %d\n", n);

    return 0;
}