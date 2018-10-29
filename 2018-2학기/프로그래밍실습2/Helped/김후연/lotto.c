#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bigyo(int a[7], int b[7])
{
    int matches = 0, bonusmatch = 1;
    for(int i = 0; i < 6;i++)
    {
        if(a[i] == b[i])
            matches =  matches + 1;
    }
    if(a[7] == b[7])
        matches = matches + bonusmatch;
    
    return matches;
}
void result(int m)
{
    printf("맞춘 개수 : %d\n", m);

    if(m == 2)
        printf("5등");
    else if(m == 3)
        printf("4등");
    else if(m == 4)
        printf("3등");
    else if(m == 5)
        printf("2등");
    else if(m == 6)
        printf("1등");
    else
        printf("꽝");

    printf("\n");
}
void autobbobgi(int a[6])
{
    for(int i = 0; i < 7 ;i++)
    {
        a[i] = rand() % 45 + 1;
    }
}

void printArr(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("%2d ", array[i]);
    puts("");
}

int main()
{
    int c[6], d[7];
    char a, b, r;
    srand( (long) time(NULL));
    do
    {
        printf("로또시작 할래? y / n : ");
        scanf(" %c", &a);

        if(a == 'n') break;

        else if(a == 'y')
        {
            printf("자동? 아님 직접? a / d : ");
            scanf(" %c",&b);

            if(b == 'a') {
                // 자동
                autobbobgi(c);
            }
            else if(b == 'd')
            {
                // 직접
                printf("1 ~ 45까지 여섯개 숫자 입력 >>(중복x)");
                for(int i = 0; i < 6;i++)
                {
                    scanf("%d", &c[i]);
                }
            }
            autobbobgi(d);
            result(bigyo(c, d));

            printf("입력번호 : ");
            printArr(c, 6);

            printf("당첨번호 : ");
            printArr(d, 6);
        }
        printf("계속할래? y / n : ");
        scanf("  %c",&r);

        if(r == 'y') continue;

        else if(r == 'n') break;
        
    } while (1);
}