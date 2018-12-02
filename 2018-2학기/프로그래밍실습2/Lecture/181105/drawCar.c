#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define PI 3.141592

HWND hwnd;
HDC hdc;

void clear_screen(void)
{
    Rectangle(hdc, 0, 0, 1000, 1000);
}

void disp_car(int car_number, int distance)
{
    if (car_number == 1)
        Rectangle(hdc, distance, 100, 50 + distance, 150);
    if (car_number == 2)
        Rectangle(hdc, distance, 200, 50 + distance, 250);
    if (car_number == 3)
        Rectangle(hdc, distance, 300, 50 + distance, 350);
}

int main(void) 
{
    int i;
    int car1_dist = 0, car2_dist = 0, car3_dist = 0;

    hwnd = GetForegroundWindow();
    hdc = GetWindowDC(hwnd);

    srand((unsigned) time(NULL));

    for (i = 0; i < 20; i++)
    {
        clear_screen();
        car1_dist += rand() % 100;
        car2_dist += rand() % 100;
        car3_dist += rand() % 100;
        disp_car(1, car1_dist);
        disp_car(2, car2_dist);
        disp_car(3, car3_dist);
        _getch();
    }
    return 0;
}