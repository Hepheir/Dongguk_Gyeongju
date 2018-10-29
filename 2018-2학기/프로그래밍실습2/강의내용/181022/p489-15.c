#include <stdio.h>

int isequalarray(int a[], int b[], int);

int main(void) {
    int arr_a[3] = { 1, 2, 3 };
    int arr_b[3] = { 2, 3, 4 };

    isequalarray(arr_a, arr_b, 3);

    int arr_c[3] = { 3, 4, 5 };
    int arr_d[3] = { 3, 4, 5 };

    isequalarray(arr_c, arr_d, 3);

    return 0;
}

int isequalarray(int a[], int b[], int len)
{
    int flag = 1;

    for (int i = 0; i < len; i++)
        if (a[i] != b[i])
            flag = 0;
    
    if (flag) puts("서로 같다.");
    else puts("서로 같지 않다.");

    return flag;
}