/*
Report9
필수
3. 345-13
4. 5명 학생의 5개 교과목성적을 배열에 저장한후,
교과목별 총점, 평균과
학생별 총점, 평균
교과목별 최고, 최저 점수 및 학생 번호
학생별 총점 최고, 최저 점수 및 학생 번호
를 출력하는 프로그램

선택
1. 344-5
2. 345-7
3. 444-8
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define ARRAY_LENGTH 20

int main(void)
{
	int i;

	int input;
	int count[10] = { 0 };

	int max_num = 0;
	
	for (i = 0; i <= ARRAY_LENGTH; i++)
	{
		printf("#%2d 0부터 9까지의 정수 입력 : ", i);
		scanf("%d", &input);

		// 잘못된 값을 입력 받으면 무효처리.
		if (input > 9 || input < 0)
		{
			puts("유효하지 않은 입력입니다.");
			i--;
			continue;
		}

		count[input]++;

		if (count[max_num] < count[input])
			max_num = input;
	}
	puts("");

	printf("가장 많이 입력 받은 수 : %d\n", max_num);
	printf("그 수의 빈도 수 : %d\n", count[max_num]);
	puts("");

	return 0;
}
