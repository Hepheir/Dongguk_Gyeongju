#include <stdio.h>

#define MESSAGE "���α׷������ �н��� �Ϲݾ���� �н��� \
                                ���� �ݺ��н��� �߿��ϴ�"
                                
#define PI 3.14
#define VOLUME(r) (4 * PI * CUBE(r) / 3)
#define SQUARE(x) ( (x) * (x) )
#define CUBE(x) ( SQUARE(x) * (x) )
#define MULT(x, y) ( (x) * (y) )

int main()
{
    double radius = 2.32;
    printf("�������� %.2lf�� ���� ü���� %.2lf �Դϴ�.", radius, VOLUME(radius));
    printf("�Ǽ� %.2lf�� ������ %.2lf �Դϴ�.\n", 4.29, SQUARE(4.29));
    printf("�Ǽ� %.2lf�� ������ %.2lf �Դϴ�.\n", 3.0, CUBE(3.0));
    printf("�Ǽ� %.2lf�� �Ǽ� %.2lf�� ���� %.2lf�Դϴ�.\n", 2.78, 3.62, MULT(2.78, 3.62));

    puts(MESSAGE);

    return 0;
}