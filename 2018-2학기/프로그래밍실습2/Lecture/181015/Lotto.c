/*
Lotto 프로그램 구현
    - 예제 10-7, 가위바위보 게임 프로그램 참조
    1) scanf()함수를 이용하여 사용자가 1~45까지 수 6개를 입력, 배열에 저장
    2) rand()함수를 이용하여 컴퓨터가 1~45까지 수 6개를 생성, 배열에 저장
    3) 사용자 배열에 있는 6개 수와 컴퓨터 배열에 있는 6개 수를 비교하여 같은 수의 개수를 구함
    4) 같은 수의 개수가
        6개면 1등
        5개면 2등
        4개면 3등
        3개면 4등
        2개 이하면 꽝
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void __init__();

void Player_chooseNum();
void Host_chooseNum();

int hasElement(int array[], int length, int elem);

int compare();
void grade(int wins);



int HOST[6], USER[6];

int main(void) {
    __init__();

    Player_chooseNum();
    Host_chooseNum();

    grade(compare());
}

void __init__() {
    long second = (long) time(NULL);
    srand(second);
}

void Player_chooseNum() {
    puts("로또!!! 1~45사이의 숫자 6개 입력 :");

    for (int i = 0; i < 6; i++) {
        printf(" [%d] : ", i + 1);
        scanf("%d", &USER[i]);

        // 예외 처리

        int InvalidInput = USER[i] > 45 || USER[i] <= 0;
        int DuplicatedInput = hasElement(USER, i, USER[i]);

        if (InvalidInput) {
            puts("<!> 잘못된 입력입니다.");
            i--;
            continue;
        }

        if (DuplicatedInput) {
            puts("<!> 중복된 입력입니다.");
            i--;
            continue;
        }
    }
}

int hasElement(int array[], int length, int elem) {
    for (int i = 0; i < length; i++)
        if (array[i] == elem)
            return 1;
    return 0;
}

void Host_chooseNum() {
    int num[45];
    int num_len = 45;
    int i;

    for (i = 0; i < 45; i++)
        num[i] = i + 1;

    int r;
    for (i = 0; i < 6; i++) {
        r = rand() % num_len;

        HOST[i] = num[r];

        // Shift @ offset 'r'
        for (int i = r; i < num_len - 1; i++)
            num[i] = num[i + 1];

        num_len--;
    }
}

int intArrayShift(int array[], int length) {
    int removed = array[0];


    return (removed);
}

int compare() {
    int wins = 0;

    for (int i = 0; i < 6; i++) {
        if (USER[i] == HOST[i])
            wins++;
    }

    // 출력해주기 시작
    printf("USER : ");
    for (int i = 0; i < 6; i++)
        printf(" [%02d]", USER[i]);

    printf("\nHOST : ");
    for (int i = 0; i < 6; i++)
        printf(" [%02d]", HOST[i]);

    puts("");
    // 출력해주기 끝

    return wins;
}

void grade(int wins) {
    printf("총 %d개를 맞추었습니다!\n", wins);

    printf("축하드립니다, ");   
    switch (wins)
    {
        case 6:
            printf("1등");
            break;
        case 5:
            printf("2등");
            break;
        case 4:
            printf("3등");
            break;
        case 3:
            printf("4등");
            break;
        default:
            printf("꽝");
            break;
    }
    puts("입니다!\n");
}