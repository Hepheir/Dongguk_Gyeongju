#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char gender;
	float height, weight, std_weight, bmi;

	printf("����(��=M, ��=W): ");
	scanf("%c", &gender);

	printf("Ű(cm): ");
	scanf("%f", &height);

	printf("������(kg): ");
	scanf("%f", &weight);

	if (gender == 'm')
		std_weight = (height / 100) * (height / 100) * 22;
	else if (gender == 'w')
		std_weight = (height / 100) * (height / 100) * 21;

	bmi = (weight - std_weight) / std_weight * 100;


	if (bmi > 20)

		printf("��");

	else if (bmi > 10)
		printf("ü�� ����");
	else if (bmi > -10)
		printf("����");


	printf("�Դϴ�.\n");

	printf("\nBMI: %f\n", bmi);

	return 0;
}

