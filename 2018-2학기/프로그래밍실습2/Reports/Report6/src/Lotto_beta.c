#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LOTTERY_COST 1000
#define BONUS_MODE true

void __init__();
void autoGenerate(int Lottery[], bool isBonus);
bool hasElement(int array[], int length, int item);
void buyLottery(int Lottery[]);
void getGradeOf(int Lottery[]);

int USER[6];
int HOST[6 + 1];

int main(void) {
    char sel;

    __init__();

    while(true) {
        buyLottery(USER);

        autoGenerate(HOST, true);
        getGradeOf(USER);

        printf("����Ͻðڽ��ϱ�? (y/n) : ");
        scanf(" %c", &sel);

        if (sel == 'n')
            break;
    }
}

void __init__() {
    long second = (long) time(NULL);
    srand(second);
}

void autoGenerate(int Lottery[], bool isBonus) {
    int num[45];
    int num_len = 45;

    for (int i = 0; i < 45; i++)
        num[i] = i + 1;

    int r;
    for (int i = 0; i < 6; i++) {
        r = rand() % num_len;

        Lottery[i] = num[r];

        for (int i = r; i < num_len - 1; i++)
            num[i] = num[i + 1];

        num_len--;
    }

    if (isBonus) {
        r = rand() % num_len;
        Lottery[6] = num[r];
    }
}

bool hasElement(int array[], int length, int item) {
    for (int i = 0; i < length; i++) {
        if (array[i] == item)
            return true;
    }
    return false;
}

// ���� �帧 ����

void buyLottery(int Lottery[]) {
    puts("������ �����մϴ�. (0�� �Է��ϸ� �ڵ�����)");
    for (int i = 0; i < 6; i++) {
        printf("  [%d] : ", i + 1);
        scanf("%d", &Lottery[i]);

        if (i == 0 && Lottery[i] == 0) {
            autoGenerate(USER, false);
            break;
        }

        if (Lottery[i] < 1 || Lottery[i] > 45) {
            puts("�߸��� �Է��Դϴ�.");
            i--;
            continue;
        }

        if (hasElement(Lottery, i, Lottery[i])) {
            puts("�ߺ��� �Է��Դϴ�.");
            i--;
            continue;
        }
    }
    
    printf("������ ���ǹ�ȣ\t: ");
    for (int i = 0; i < 6; i++) {
        printf("[%2d] ", USER[i]);
    }
    printf("\n");
}

void getGradeOf(int Lottery[]) {
    int matches = 0;
    bool match_bonus = false;
    
    printf("�̹�ȸ ��÷��ȣ\t: ");
    for (int i = 0; i < 6; i++) {
        printf("[%2d] ", HOST[i]);

        for (int j = 0; j < 6; j++) {
            if (i == j) continue;

            if (Lottery[i] == HOST[j]) {
                matches++;
                break;
            }
        }
    }
    if (BONUS_MODE) {
        printf("[%2d]", HOST[6]);

        for (int i = 0; i < 6; i++)
            if (HOST[6] == Lottery[i]) {
                match_bonus = true;
                break;
            }
    }
    puts("\n");

    long unsigned int CREDIT;

    printf("���� %d���� ���߼̱���!\n", matches);
    printf("���ϵ帳�ϴ�, ");
    switch (matches)
    {
        case 6: // 1��
            puts("1���Դϴ�.");
            CREDIT = LOTTERY_COST * (long unsigned int) 8145060;
            break;

        case 5: // 2��
            if (match_bonus) {
                puts("2���Դϴ�.");
                CREDIT = LOTTERY_COST * (long unsigned int) 1357510;
            } else {
                puts("3���Դϴ�.");
                CREDIT = LOTTERY_COST * (long unsigned int) 35724;
            }
            break;

        case 4: // 3��
            puts("4���Դϴ�.");
            CREDIT = LOTTERY_COST * 733;
            break;

        case 3: // 4��
            puts("5���Դϴ�.");
            CREDIT = LOTTERY_COST * 45;
            break;
    
        default:
            puts("���Դϴ�.");
            CREDIT = 0;
            break;
    }  
    printf("��÷���� %ldW �Դϴ�!\n", CREDIT);
    puts("");
}