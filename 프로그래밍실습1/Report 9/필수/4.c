#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// double������ ����
#define STUDENTS 5
#define SUBJECTS 5

int main(void)
{
    // rand�Լ��� ���� �ð��� �������� (���� ����)�� �ǵ��� �ϱ����� ����ϴ� �Լ�
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
            // # ��� ������ ������ �Է� (0�̻� 100������ ����)
            score[i][j] = (rand() % 101);

            // # �Էµ� ������ ������ ����.
            studentTotal[i] += score[i][j];
            subjectTotal[j] += score[i][j];

            // # ������ �� �ְ�, ���������� Ȯ��
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
        // # �л��� ���� �ְ�, ���������� Ȯ��
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


	// ������ ����, ��� / �ְ�, ���� ���� �� �л� ��ȣ ���
	puts("===== ���� ���� & ��� =====");

    for (i = 0; i < SUBJECTS; i++)
    {
	    puts("");
        printf("%d�� ����", i);
        printf("  ���� : %d\n", subjectTotal[i]);
        printf("  ��� : %.2lf\n", subjectTotal[i] / (double) SUBJECTS);
        printf("  �ְ� ���� (�л���ȣ) : %3d(%d)\n", maxScore[i], maxStudent[i]);
        printf("  ���� ���� (�л���ȣ) : %3d(%d)\n", minScore[i], minStudent[i]);
    }
    puts("");

	// �л��� ����, ��� / �ְ�, ���� ���� �� �л� ��ȣ ���
	puts("===== �л��� ���� & ��� =====");

    for (i = 0; i < STUDENTS; i++)
    {
	    puts("");
        printf("%d�� �л�", i);
        printf("  ���� : %d\n", subjectTotal[i]);
        printf("  ��� : %.2lf\n", subjectTotal[i] / (double) SUBJECTS);
    }
    puts("");

    printf("�ְ� ���� (�л���ȣ) : %3d(%d)\n", maxTotal, maxTotalStudent);
    printf("���� ���� (�л���ȣ) : %3d(%d)\n", minTotal, minTotalStudent);
    puts("");

	return 0;
}