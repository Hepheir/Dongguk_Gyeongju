#include <stdio.h>

int first();
int second();
int third();
int fourth();

int main() {

    puts("\n1, ����� �׸��� ���� : �ڱ�Ұ��� ��Ģ����\n");
    first();

    puts("\n2, �ڷ��� : ������ ��ҹ��� ����\n");
    second();

    puts("\n3, ����-������������ ���� : ������������ ����, ���׿������� ����\n");
    third();

    puts("\n4, �������ڿ� �ݺ��� : ���� ���̴� ������\n");
    fourth();

    return 0;
}

int first() {
    puts("�й�:\t2018212236");
    puts("�̸�:\t�赿��");


    float n1, n2;

    n1 = 96.59875;
    n2 = 14.00712;


    printf("n1: %f\nn2: %f\n", n1, n2);

    // ��
    float n_sum = n1 + n2;
    printf("n1 + n2 = %f\n", n_sum);

    // ��
    float n_sub = n1 - n2;
    printf("n1 - n2 = %f\n", n_sub);

    // ��
    float n_mul = n1 * n2;
    printf("n1 * n2 = %f\n", n_mul);

    // ��
    float n_div = n1 / n2;
    printf("n1 / n2 = %f\n", n_div);
    return 0;

}

int second() {
    char c = 'a';
    printf("Before case change\nc: %c\n", c);

    if (c < 97)
        c = c + 32;
    else
        c = c - 32;

    printf("After case change\nc: %c\n", c);

    return 0;
}

int third() {
    int a = 10, b = 11, c = 0;
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (++a == 11) && (++b == 12);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (a-- == 10) && (b-- == 12);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (a++ == 10) || (b++ == 11);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (--a == 11) || (--b == 11);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    
    int n;
    printf("N�� �Է����ּ��� : ");
    scanf("%d", &n);

    (n % 2) ?
        printf("N�� ¦��, N^3 = %d\n", n * n * n) :
        printf("N�� Ȧ��, N^2 = %d\n", n * n);

    return 0;
}


int fourth() {
    char isLier;

    int Innesim = 9;

    printf("����� �������� �� ���� �ֽ��ϱ�? (Y/N)\n");
    scanf("%c", &isLier);

    while(1)
    {
        if (isLier == 'Y' || isLier == 'y')
        {
            printf("�˰� �־����.\n");
            break;
        }

        if (Innesim < 0)
        {
            printf("������ ġ������.\n");
            break;
        }

        printf("��¥�� ����� �������� �� ���� ������? (Y/N): ");
        scanf(" %c", &isLier);

        // ���������� �����Ͽ����� �ѱ� ������ �°� ����� ���� �����ش�.
        isLier = (isLier == 'Y' || isLier == 'y') ? 'N' : 'Y';

        Innesim--;
    }

    return 0;
}