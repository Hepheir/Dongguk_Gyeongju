#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int i, j;

	float score[6][6] = { 0 };

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d번 학생 %d번 과목 성적 입력 : ", i + 1, j + 1);
			scanf("%f", &score[i][j]);

			score[i][4] += score[i][j]; // 학생 점수 합계
		}

		score[i][5] = score[i][4] / 4; // 학생 점수 평균
	}

	for (j = 0; j < 4; j++) {
		for (i = 0; i < 4; i++) {
			score[4][j] += score[i][j]; // 과목 합계
		}

		score[5][j] = score[4][j] / 4; // 과목 평균
	}

	// 출력

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++)
			printf("%3.2f\t", score[i][j]);
		puts("");
	}

	system("pause");
	return 0;
}