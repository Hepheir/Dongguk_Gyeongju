#include <stdio.h>
#include <stdlib.h>
#include "my_atmega128.h"

void printScr();

char SCREEN[16] = { 0 };

char message[100];

int main(void)
{
    scanf("%s", message);
    for (int i = 0; i < 1000; i++)
    {
        SCREEN[i % 16] = message[i];
        printScr();
        Delay_ms(100000);
    }
}

void printScr() {
    for (int i = 0; i < 16; i++)
        printf("%c", SCREEN[i]);
    puts("");
}