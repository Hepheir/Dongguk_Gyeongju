#include <stdio.h>

int main(void)
{
    int input, position, deca = 10;

    scanf("%d", &input);

    do
    {
        // deca 자릿 수 위로 자름
        position = input % deca;

        input -= position;

        // deca 자릿 수 아래로 자름
        position /= deca / 10;

        printf("%d", position);

        deca *= 10;
    }
    while (input > 0);

    puts("");

    return 0;
}