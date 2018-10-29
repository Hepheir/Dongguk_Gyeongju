#include <stdio.h>

int main(void) {
    double data1 = 5.5;
    double data2 = 6.6;

    double *pD1 = &data1;
    double *pD2 = &data2;

    double sum, diff;
    double **dp;

    dp = &pD1;
    **dp = 8.8;

    sum  = **dp;
    diff = **dp;

    dp = &pD2;
    **dp = 9.9;

    sum  = sum + **dp;
    diff = diff - **dp;

    printf("data1 : %lf\n", data1);
    printf("data2 : %lf\n", data2);
    printf("sum : %lf\n",  sum);
    printf("diff : %lf\n", diff);

    return 0;
}