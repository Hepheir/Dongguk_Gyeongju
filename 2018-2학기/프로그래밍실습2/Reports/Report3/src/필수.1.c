/*
* 5명의 학생의 5개 교과목 성적 산출 프로그램 구현. 학생별 성적 총합 및 평균, 과목별 성적 총합 및 평균을 구하여 2차원 형태로 성적 결과를 출력.
* 단. 성적은 표준입력장치로부터 입력 받는 방식으로 구현.
*/

#include <stdio.h>

#define STUDENTS 5
#define SUBJECTS 5

int main() {
	int i, j;

	float score[STUDENTS + 2][SUBJECTS + 2] = { 0 };

	for (i = 0; i < STUDENTS; i++) {
		for (j = 0; j < SUBJECTS; j++) {
			printf("%d번 학생 %d번 과목 성적 입력 : ", i + 1, j + 1);
			scanf("%f", &score[i][j]);

			score[i][SUBJECTS] += score[i][j]; // 학생 점수 합계
		}

		score[i][SUBJECTS + 1] = score[i][SUBJECTS] / SUBJECTS; // 학생 점수 평균
	}

	for (j = 0; j < SUBJECTS; j++) {
		for (i = 0; i < STUDENTS; i++) {
			score[STUDENTS][j] += score[i][j]; // 과목 합계
		}

		score[STUDENTS + 1][j] = score[STUDENTS][j] / STUDENTS; // 과목 평균
	}

	// 출력

	for (i = 0; i < STUDENTS + 2; i++) {
		for (j = 0; j < SUBJECTS + 2; j++)
			printf("%3.2f\t", score[i][j]);
		puts("");
	}

	return 0;
}