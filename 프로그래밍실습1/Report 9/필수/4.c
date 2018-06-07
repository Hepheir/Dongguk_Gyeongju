#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// double형으로 선언
#define STUDENTS 5
#define SUBJECTS 5

int main(void)
{
    // rand함수가 현재 시간을 기준으로 (완전 난수)가 되도록 하기위해 사용하는 함수
    srand(time(NULL));

    int i, j;

	int score[STUDENTS][SUBJECTS] = {0};

	int maxScore[SUBJECTS] = {0};
    int maxStudent[SUBJECTS];

    int minScore[SUBJECTS] = {100};
    int minStudent[SUBJECTS];

    int studentTotal[STUDENTS] = {0};
    int subjectTotal[SUBJECTS] = {0};

    int maxTotal = 0;
    int maxTotalStudent;

    int minTotal = 100 * SUBJECTS;
    int minTotalStudent;

    for (i = 0; i < STUDENTS; i++)
        for (j = 0; j < SUBJECTS; j++)
        {
            // # 모든 성적을 난수로 입력 (0이상 100이하의 난수)
            score[i][j] = (rand() % 101);

            // # 입력된 성적을 총점에 누계.
            studentTotal[i] += score[i][j];
            subjectTotal[j] += score[i][j];

            // # 교과목 별 최고, 최저점인지 확인
            if (maxScore[j] < score[i][j])
            {
                maxScore[j] = score[i][j];
                maxStudent[j] = i;
            }

            if (minScore[j] > score[i][j])
            {
                minScore[j] = score[i][j];
                minStudent[j] = i;
            }
        }

    for (i = 0; i < STUDENTS; i++)
    {
        // # 학생별 총점 최고, 최저점인지 확인
        if (maxTotal < studentTotal[i])
        {
            maxTotal = studentTotal[i];
            maxTotalStudent = i;
        }

        if (minTotal > studentTotal[i])
        {
            minTotal = studentTotal[i];
            minTotalStudent = i;
        }
    }


	// 교과목별 총점, 평균 / 최고, 최저 점수 및 학생 번호 출력
	puts("===== 과목별 총점 & 평균 =====");

    for (i = 0; i < SUBJECTS; i++)
    {
	    puts("");
        printf("%d번 과목", i);
        printf("  총점 : %d\n", subjectTotal[i]);
        printf("  평균 : %.2lf\n", subjectTotal[i] / (double) SUBJECTS);
        printf("  최고 점수 (학생번호) : %3d(%d)\n", maxScore[i], maxStudent[i]);
        printf("  최저 점수 (학생번호) : %3d(%d)\n", minScore[i], minStudent[i]);
    }
    puts("");

	// 학생별 총점, 평균 / 최고, 최저 점수 및 학생 번호 출력
	puts("===== 학생별 총점 & 평균 =====");

    for (i = 0; i < STUDENTS; i++)
    {
	    puts("");
        printf("%d번 학생", i);
        printf("  총점 : %d\n", subjectTotal[i]);
        printf("  평균 : %.2lf\n", subjectTotal[i] / (double) SUBJECTS);
    }
    puts("");

    printf("최고 총점 (학생번호) : %3d(%d)\n", maxTotal, maxTotalStudent);
    printf("최저 총점 (학생번호) : %3d(%d)\n", minTotal, minTotalStudent);
    puts("");

	return 0;
}