/*
	솔루션 / 프로젝트 / 소스파일: Ch03 / Prj09 / overflow.c
	오버플로와 언더플로의 발생
	V 1.0 2016.
*/

#include <stdio.h>

int main(void)
{
	unsigned char	uc = 255 + 1;
	short			s = 32767 + 1;
	float			min = 1.175E-50;
	float			max = 3.403E39;

	printf("%u\n", uc);		//오버플로 발생
	printf("%d\n", s);		//오버플로 발생
	printf("%e\n", min);	//언더플로 발생
	printf("%f\n", max);	//오버플로 발생

	return 0;
}