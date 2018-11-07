#include <Windows.h>
#include <stdio.h>

HWND hwnd;
HDC hdc;

int main(void)
{
    int x, y;

    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);

    MoveToEx(hdc, 100, 300, 0);
    LineTo(hdc, 300, 300);

    MoveToEx(hdc, 100, 300, 0);
    LineTo(hdc, 100, 0);

    for (x = 0; x < 300; x++)
    {
        y = 0.01 * x * x + x;
        SetPixel(hdc, 100 + x, 300 - y, RGB(255, 0, 0));
    }
    return 0;
}