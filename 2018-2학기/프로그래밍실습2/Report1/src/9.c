#include <stdio.h>

int main()
{
   char isLier;

   int Innesim = 9;

   printf("����� �������� �� ���� �ֽ��ϱ�? (Y/N) : ");
   scanf("%c", &isLier);

   while(1)
   {
       if (isLier == 'Y' || isLier == 'y')
       {
           printf("�˰� �־����.\n");
           break;
       }

       if (Innesim < 0)
       {
           printf("������ ġ������.\n");
           break;
       }

       printf("��¥�� ����� �������� �� ���� ������? (Y/N): ");
       scanf(" %c", &isLier);

       // ���������� �����Ͽ����� �ѱ� ������ �°� ����� ���� �����ش�.
       isLier = (isLier == 'Y' || isLier == 'y') ? 'N' : 'Y';

       Innesim--;
   }

   return 0;
}