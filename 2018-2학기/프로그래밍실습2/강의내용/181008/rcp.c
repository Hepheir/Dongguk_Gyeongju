#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 구분선 그리는 함수
void printScr_Hr_Bold();
void printScr_Hr();

// 게임 흐름 제어
void __init__();

void Player_bet();
void Player_select();
void Player_match();
void Player_status();

void GameOver();

// 글로벌 변수

int CREDIT;
int BET;
int CPU, USER;

int WIN = 0, DRAW = 0, LOSE = 0;
int COMBO = 0, MAX_COMBO = 0;

int main(void) {
    __init__();

    while (1) {
        Player_bet();
        if (BET == 0) break;

        CPU = rand() % 3 + 1;

        Player_select();
        Player_match();

        Player_status();

        if (CREDIT <= 0) break;
    }

    GameOver();
    return 0;
}

// 함수 원형

void __init__() {
    long seconds = (long) time(NULL);
    srand(seconds);

    printScr_Hr_Bold();

    puts(" 가위 바위 보 게임!!");

    printScr_Hr_Bold();

    puts(" 크레딧을 넣어주세요...");
    puts("");
    printf(">>> $");

    scanf("%d", &CREDIT);
}

void Player_bet() {
    printScr_Hr_Bold();

    puts("얼마를 배팅하시겠습니까?");
    puts("($0을 베팅하면 종료)");
    printf("현재 보유 크레딧 : $%d\n", CREDIT);
    puts("");
    printf(">>> $");

    scanf("%d", &BET);
    CREDIT -= BET;

    if (CREDIT < 0) {
        CREDIT += BET;
        puts("감당 못하실 금액을 입력하셨습니다.");

        Player_bet();
    }
}

void Player_select() {
    printScr_Hr();

    puts(" 무엇을 내시겠습니까?");
    puts("");
    puts(" 1. 가위");
    puts(" 2. 바위");
    puts(" 3. 보");
    puts("");
    printf(">>> ");

    scanf("%d", &USER);

    // Error Handling.
    if (USER != 1 && USER != 2 && USER != 3) {
        puts("올바르지 않은 입력입니다!");

        Player_select();
    }
}

void Player_match() {
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
        DRAW++;
        COMBO = 0;

        puts("비겼다.");
        printf("베팅한 크레딧 $%d을 돌려받았다.\n", BET);
        
        CREDIT += BET;
        return;
    }

    // 비기지 않았을 경우, CPU가 유저를 이겼는지 검사.

    if (++USER > 3) USER = 1;

    if (USER == CPU) {
        LOSE++;
        COMBO = 0;
        
        puts("졌다...");
        printf("베팅한 크레딧 $%d을 잃었다.\n", BET);

        return;
    }

    // CPU가 유저를 이기지 못했으면 유저의 승리 외엔 경우의 수가 없다.

    printf("이겼다!!!\n");
    WIN++;
    COMBO++;

    if (MAX_COMBO < COMBO)
        MAX_COMBO = COMBO;

    BET *= 1 + COMBO;
    printf("베팅한 크레딧의 %d배인 $%d을 벌었다.\n", 1 + COMBO, BET);

    CREDIT += BET;
}

void Player_status() {
    printScr_Hr();

    printf("현재 전적 : %d 회", (WIN + LOSE + DRAW));

    if (COMBO) printf(" (%d 연승 중)", COMBO);

    puts("");
    printf(" %d 승, %d 패, %d 무, 최대 %d 연승\n", WIN, LOSE, DRAW, MAX_COMBO);

    printf("현재 승률 : %.1f%% (무승부 제외)\n", (float) WIN / (WIN + LOSE) * 100);
}

void GameOver() {
    printScr_Hr_Bold();
    puts("파산하셨습니다.");
}

void printScr_Hr_Bold() {
    puts("====================================");
}

void printScr_Hr() {
    puts("------------------------------------");
}
