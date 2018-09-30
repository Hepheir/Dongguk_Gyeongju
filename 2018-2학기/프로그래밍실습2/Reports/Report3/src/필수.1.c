/*
* 5���� �л��� 5�� ������ ���� ���� ���α׷� ����. �л��� ���� ���� �� ���, ���� ���� ���� �� ����� ���Ͽ� 2���� ���·� ���� ����� ���.
* ��. ������ ǥ���Է���ġ�κ��� �Է� �޴� ������� ����.
*/

#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 5

int main() {
	int i, j;

	float score[STUDENTS + 2][SUBJECTS + 2] = { 0 };

	for (i = 0; i < STUDENTS; i++) {
		for (j = 0; j < SUBJECTS; j++) {
			printf("%d�� �л� %d�� ���� ���� �Է� : ", i + 1, j + 1);
			scanf("%f", &score[i][j]);

			score[i][SUBJECTS] += score[i][j]; // �л� ���� �հ�
		}

		score[i][SUBJECTS + 1] = score[i][SUBJECTS] / SUBJECTS; // �л� ���� ���
	}

	for (j = 0; j < SUBJECTS; j++) {
		for (i = 0; i < STUDENTS; i++) {
			score[STUDENTS][j] += score[i][j]; // ���� �հ�
		}

		score[STUDENTS + 1][j] = score[STUDENTS][j] / STUDENTS; // ���� ���
	}

	// ���

	for (i = 0; i < STUDENTS + 2; i++) {
		for (j = 0; j < SUBJECTS + 2; j++)
			printf("%3.2f\t", score[i][j]);
		puts("");
	}

	return 0;
}