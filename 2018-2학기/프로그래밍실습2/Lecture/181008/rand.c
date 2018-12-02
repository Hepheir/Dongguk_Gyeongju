#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("1 - %5d 사이의 난수 5개:\n", RAND_MAX);
    for (int i = 0; i < 5; i++)
        printf("%5d ", rand());
    puts("");

    return 0;
}