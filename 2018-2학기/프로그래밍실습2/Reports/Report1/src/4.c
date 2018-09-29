#include <stdio.h>

#define MESSAGE "프로그램언어의 학습은 일반언어의 학습과 \
                                같이 반복학습이 중요하다"
                                
#define PI 3.14
#define VOLUME(r) (4 * PI * CUBE(r) / 3)
#define SQUARE(x) ( (x) * (x) )
#define CUBE(x) ( SQUARE(x) * (x) )
#define MULT(x, y) ( (x) * (y) )

int main()
{
    double radius = 2.32;
    printf("반지름이 %.2lf인 구의 체적은 %.2lf 입니다.", radius, VOLUME(radius));
    printf("실수 %.2lf의 제곱은 %.2lf 입니다.\n", 4.29, SQUARE(4.29));
    printf("실수 %.2lf의 제곱은 %.2lf 입니다.\n", 3.0, CUBE(3.0));
    printf("실수 %.2lf와 실수 %.2lf의 곱은 %.2lf입니다.\n", 2.78, 3.62, MULT(2.78, 3.62));

    puts(MESSAGE);

    return 0;
}