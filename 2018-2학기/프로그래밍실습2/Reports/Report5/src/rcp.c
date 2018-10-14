#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void __init__();

void Select();
void Match();

void printScr_Hr_Bold();
void printScr_Hr();

int CPU, USER;

int main(void) {
    __init__();

    while (1) {
        Select();
        if (USER == 0) break;

        CPU = rand() % 3 + 1;

        Match();
    }

    return 0;
}

void __init__() {
    long seconds = (long) time(NULL);
    srand(seconds);

    printScr_Hr_Bold();

    puts(" 가위 바위 보 게임!!");

    printScr_Hr_Bold();
}

void Select() {
    printScr_Hr();

    puts(" 무엇을 내시겠습니까?");
    puts("");
    puts(" 1. 가위");
    puts(" 2. 바위");
    puts(" 3. 보");
    puts("");
    puts(" 0. 종료");
    printf(">>> ");

    scanf("%d", &USER);
}

void Match() {
    printScr_Hr();

    printf("컴퓨터는 ");
    
    switch (CPU)
    {
        case 1:
            printf("가위");
            break;
        case 2:
            printf("바위");
            break;
        case 3:
            printf("보");
            break;
    }

    printf("를, 당신은 ");
    
    switch (USER)
    {
        case 1:
            printf("가위");
            break;
        case 2:
            printf("바위");
            break;
        case 3:
            printf("보");
            break;
    }
    puts("를 냈다.\n");

    // 승부를 판가름 하는 부분.

    if (USER == CPU) {
        puts("비겼다.");
        return;
    }

    // 비기지 않았을 경우, CPU가 유저를 이겼는지 검사.

    if (++USER > 3) USER = 1;

    if (USER == CPU) {
        puts("졌다...");
        return;
    }

    // CPU가 유저를 이기지 못했으면 유저의 승리 외엔 경우의 수가 없다.

    printf("이겼다!!!\n");
    return;
}

void printScr_Hr_Bold() {
    puts("====================================");
}

void printScr_Hr() {
    puts("------------------------------------");
}