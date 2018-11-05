#include <Windows.h>
#include <math.h>
#include <stdio.h>

HWND hwnd;
HDC hdc;
double rad(double degree) // 도를 라디안으로 변환
{
    return PI * degree / 180.0;
}

int main(void)
{
    int degree, x, y;
    double radian, result;

    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);

    MoveToEx(hdc, 30, 200, 0);
    LineTo(hdc, 500, 200);

    MoveToEx(hdc, 30, 200, 0);
    LineTo(hdc, 30, 0);

    for (degree = 0; degree <= 360; degree++)
    {
        result = sin(rad((double)degree));
        x = degree + 30;
        y = 200 - (int)(100.0 * result);
        SetPixel(hdc, x, y, RGB(255, 0, 0));
    }
    return 0;
}