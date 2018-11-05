#include <windows.h>
#include <stdio.h>

HWND hwnd;
HDC hdc;

int main(void) 
{
    int x1, y1, x2, y2, i;

    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);

    x1 = 50;
    y1 = 50;

    for (i = 0; i < 5; i++)
    {
        x2 = x1 + 30;
        y2 = y1 + 30;

        Rectangle(hdc, x1, y1, x2, y2);
        Ellipse(hdc, x1, y1, x2, y2);
        x += 100;
        printf("\n");
    }
    return 0;
}