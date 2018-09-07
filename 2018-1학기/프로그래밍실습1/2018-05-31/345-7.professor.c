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

int main(void)
{
	int n;

	printf("각 자릿수를 뒤집을 정수 입력: ");
	scanf("%d", &n);

	do
	{
		printf("%d", n % 10);
		n /= 10;
	} while (n > 0);

	puts("");

	return 0;
}
