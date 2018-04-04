// CRT SECURE WARNING

#include <stdio.h>

int main(void)
{
    float f_temp, c_temp;

    printf("화씨온도를 소수로 입력하세요: ");
    scanf("%f", &f_temp);

    c_temp = 5.0 / 9.0 * (f_temp - 32.0);

    printf("섭씨온도로 바꾸면 %.4f에요.\n", c_temp);

    return 0;
}