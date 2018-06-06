#include <stdio.h>

#define LINE_LENGTH 9

int main(void) {
    int i, linebreaks = 0;

    for (i = 1; i <= 1000; i++)
    {
        // 7의 배수도 아니면서 11의 배수도 아니면 continue.
        if (i % 7 && i % 11)
            continue;
       
        printf(" %4d", i);
        linebreaks++;

        if (linebreaks % LINE_LENGTH)
            continue;
        
        puts("");
    }

    return 0;
}