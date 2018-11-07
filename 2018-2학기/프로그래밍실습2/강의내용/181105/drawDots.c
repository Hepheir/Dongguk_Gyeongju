#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

HWND hwnd;
HDC hdc;

int main(void) {
    int i, x, y, red, green, blue;

    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);

    srand((unsigned) time(NULL));
    for (i = 0; i < 10000; i++)
    {
        x = rand() % 300;
        y = rand() % 300;

        red = rand() %256;
        green = rand() % 256;
        blue = rand() % 256;

        SetPixel(hdc, x, y, RGB(red, green, blue));
    }
    _getch();
    return 0;
}