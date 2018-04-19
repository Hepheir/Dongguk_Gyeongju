#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char gender;
	float height, weight, std_weight, bmi;

	printf("성별(남=M, 여=W): ");
	scanf("%c", &gender);

	printf("키(cm): ");
	scanf("%f", &height);

	printf("몸무게(kg): ");
	scanf("%f", &weight);

	if (gender == 'm')
		std_weight = (height / 100) * (height / 100) * 22;
	else if (gender == 'w')
		std_weight = (height / 100) * (height / 100) * 21;

	bmi = (weight - std_weight) / std_weight * 100;


	if (bmi > 20)

		printf("비만");

	else if (bmi > 10)
		printf("체중 과다");
	else if (bmi > -10)
		printf("정상");


	printf("입니다.\n");

	printf("\nBMI: %f\n", bmi);

	return 0;
}

