#include <stdio.h>

int main() {
	// ������ �迭�� �����ϸ鼭 �ʱⰪ���� ù ���ҿ� ���� 'A'�� ������ ��
	// �ٸ� ���ĺ� �빮�ڸ� �迭�� ���ĺ������� ������ �� ����ϴ� �ñ׷�
	// ����

	char ch[26];

	for (int i = 0; i < 26; i++)
		ch[i] = 'A' + i;

	for (int i = 0; i < 26; i++)
		printf("%c", ch[i]);

	system("pause");
	return 0;
}