#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int i, j;

	float score[6][6] = { 0 };

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d�� �л� %d�� ���� ���� �Է� : ", i + 1, j + 1);
			scanf("%f", &score[i][j]);

			score[i][4] += score[i][j]; // �л� ���� �հ�
		}

		score[i][5] = score[i][4] / 4; // �л� ���� ���
	}

	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {
			score[4][j] += score[i][j]; // ���� �հ�
		}

		score[5][j] = score[4][j] / 4; // ���� ���
	}

	// ���

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++)
			printf("%3.2f\t", score[i][j]);
		puts("");
	}

	system("pause");
	return 0;
}