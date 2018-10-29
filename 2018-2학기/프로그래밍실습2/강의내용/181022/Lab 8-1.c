#include <stdio.h>

int main(void)
{
    char c = '@';
    char *pc = &c;
    int m = 100;
    int *pm = &m;
    double x = 5.83;
    double *px = &x;

    printf("변수명   주소값   저장값\n");
    printf("--------------------------------------\n");
    printf("%3s %12p %c\n", "c", &c, c);
    printf("%3s %12p %p\n", "pc", &pc, pc);
    printf("%3s                %c\n", "*pc", *pc);
    printf("%3s %12p %d\n", "m", &m, m);
    printf("%3s %12p %p\n", "pm", &pm, pm);
    printf("%3s                %d\n", "*pm", *pm);
    printf("%3s %12p %lf\n", "x", &x, x);
    printf("%3s %12p %p\n", "px", &px, px);
    printf("%3s                %lf\n", "*px", *px);

    return 0;
}