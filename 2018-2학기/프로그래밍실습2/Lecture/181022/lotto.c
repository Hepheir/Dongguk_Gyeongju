#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void autoGenerate(int *lotteryArray);
bool hasElement(int *array, int length, int elem);
int countMatches(int arr_1[], int arr_2[], int length);

int main(void)
{
    int USER[6];
    int HOST[6];

    char userCond;

    int matches, grade;

    long second = time(NULL);
    srand(second);

    while (1)
    {
        // 게임의 반복 여부 결정
        printf("새 게임을 하시겠사와요? (y/n) : ");
        scanf(" %c", &userCond);
        if (userCond == 'n') break;

        // 자동생성 여부 결정
        printf("자동생성 하시겠습니까? (y/n) : ");
        scanf(" %c", &userCond);

        if (userCond == 'y') {
            autoGenerate(USER);
        } else {
            // 복권 번호 직접 입력
            for (int i = 0; i < 6; i++)
            {
                printf("%d번째 번호 : ", (i + 1));
                scanf("%d", &USER[i]);
            }
        }

        // 당첨 번호 생성
        autoGenerate(HOST);

        // 등수 확인
        matches = countMatches(USER, HOST, 6);
        printf("%d개를 맞추었습니다.", matches);

        if (matches >= 3) {
            grade = 6 - matches + 1;
            printf("%d등 입니다.\n", grade);
        } else {
            printf("꽝 입니다.\n");
        }
    }
}

void autoGenerate(int *lotteryArray) {
    int r;

    for (int i = 0; i < 6; i++)
    {
        r = rand() % 45 + 1;

        if (hasElement(lotteryArray, i, r))
        {
            i--;
            continue;
        }

        *(lotteryArray + i) = r;
    }
}

bool hasElement(int *array, int length, int elem)
{
    for (int i = 0; i < length; i++)
        if (*(array + i) == elem)
            return true;

    return false;
}

int countMatches(int arr_1[], int arr_2[], int length)
{
    int count = 0;

    for (int i = 0; i < length; i++)
        if (arr_1[i] == arr_2[i])
            count++;
    
    return count;
}