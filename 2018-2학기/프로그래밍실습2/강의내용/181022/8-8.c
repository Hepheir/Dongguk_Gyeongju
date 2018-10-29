#include <stdio.h>

int main(void)
{
    int i = 20;
    int *pi = &i;
    int **dpi = &pi;

    printf("%p %p %p\n", &i, pi, *dpi);
    
    printf("======================================\n");

    printf("변수명     주소값   저장값\n");
    printf("--------------------------------------\n");
    printf("%5s %12p %d\n", "i", &i, i);
    printf("%5s %12p %p\n", "pi", &pi, pi);
    printf("%5s                %d\n", "*pi", *pi);
    printf("%5s %12p %p\n", "dpi", &dpi, dpi);
    printf("%5s                %p\n", "*dpi", *dpi);
    printf("%5s                %d\n", "**dpi", **dpi);

    printf("======================================\n");
    
    *pi = i + 2;
    printf("%d %d %d\n", i, *pi, **dpi);
    
    printf("======================================\n");

    printf("변수명     주소값   저장값\n");
    printf("--------------------------------------\n");
    printf("%5s %12p %d\n", "i", &i, i);
    printf("%5s %12p %p\n", "pi", &pi, pi);
    printf("%5s                %d\n", "*pi", *pi);
    printf("%5s %12p %p\n", "dpi", &dpi, dpi);
    printf("%5s                %p\n", "*dpi", *dpi);
    printf("%5s                %d\n", "**dpi", **dpi);
    
    printf("======================================\n");

    **dpi = *pi + 2;
    printf("%d %d %d\n", i, *pi, **dpi);
    
    printf("======================================\n");

    printf("변수명     주소값   저장값\n");
    printf("--------------------------------------\n");
    printf("%5s %12p %d\n", "i", &i, i);
    printf("%5s %12p %p\n", "pi", &pi, pi);
    printf("%5s                %d\n", "*pi", *pi);
    printf("%5s %12p %p\n", "dpi", &dpi, dpi);
    printf("%5s                %p\n", "*dpi", *dpi);
    printf("%5s                %d\n", "**dpi", **dpi);

    return 0;
}